/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 20:08:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date() {}

Date::Date(const std::string& s)
{
	std::istringstream iss(s);
	std::istringstream iss2(s);
    char dash;
    std::string tmp;

    iss >> _year >> dash >> _month >> dash >> _day;
    while (std::getline(iss2, tmp, '-'))
	{
		for (size_t i = 0; i < tmp.length(); i++)
		{
			if (!std::isdigit(tmp[i]))
				throw std::invalid_argument("bad input => " + s);
		}
	}
	if (isValid() == false)
		throw std::invalid_argument("bad input => " + s);
}

Date::Date(const Date& d) { *this = d; }

Date&	Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return (*this);
}

bool	Date::operator>(const Date& d) const
{
	if (_year > d._year)
        return true;
    else if (_year == d._year && _month > d._month)
        return true;
    else if (_year == d._year && _month == d._month && _day > d._day)
        return true;
    return false;
}

bool	Date::operator<(const Date& d) const
{
	return !(*this > d);
}


bool	Date::operator==(const Date& d) const
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	return false;
}

bool	Date::isValid() const
{
	tm date;
    
	/* tm_year is expecting this the years after 1900 */
    date.tm_year = _year - 1900;
	/* the months start at index 0 */
    date.tm_mon = _month - 1;
    date.tm_mday = _day;

    /*
	Check if the date is outside any rational input values.
	Convert to t_time with mktime and verify if that
	day of that month of that year does actually exists.
	*/
	return (!(_year <= 0 || (_month > 12 || _month == 0) || (_day > 31 || _day == 0)) && std::mktime(&date) != -1)? true : false;
}

Date::~Date() {}

BitcoinExchange::BitcoinExchange(const std::string& inputFile) : _inputFile(inputFile)
{
	if (!isValidFile("data.csv")) throw std::runtime_error("There is no database");
	std::ifstream	fileName("data.csv");
	std::string		line;
	bool			head = true;
	std::pair<std::string, float> tmp;

	while (std::getline(fileName, line))
	{
		if (head)
		{
			head = false;
			continue ;
		}
		try
		{
			tmp = parseDBLine(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
		_db.insert(tmp);
	}
	// std::cout << _db.size() << std::endl;
}

void	BitcoinExchange::makeQuery() const
{
	std::ifstream	fileName(_inputFile.c_str());
	std::string		line;
	bool			head = true;
	bool			toPrint = false;
	std::pair<std::string, float> tmp;

	while (std::getline(fileName, line))
	{
		if (head == false)
		{
			// Store in a map
			try
			{
				tmp = parseLine(line);
				toPrint = true;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				toPrint = false;
			}
			if (toPrint) printValue(tmp);
		}
		else
			head = false;
	}
}

bool	BitcoinExchange::isBigger(const std::string& dt1, const std::string& dt2) const
{
	Date	date1(dt1);
	Date	date2(dt2);

	return (date1 > date2);
}

bool	BitcoinExchange::isSmaller(const std::string& dt1, const std::string& dt2) const
{
	Date	date1(dt1);
	Date	date2(dt2);

	return (date1 < date2);
}

bool	BitcoinExchange::isEqual(const std::string& dt1, const std::string& dt2) const
{
	Date	date1(dt1);
	Date	date2(dt2);

	return (date1 == date2);
}

/*
Returns the value of the date that is querried. If the date
is not in the db, searches the closes lower date.
*/
#include <unistd.h>
float	BitcoinExchange::findValue(const std::string& d) const
{
	std::pair<std::string, float>	tmp;
	std::pair<std::string, float>	next;
	bool							start = true;
	float							out;
	std::map<std::string, float>::const_iterator itr = _db.begin();
	while (itr != _db.end())
	{
		tmp = *itr;
	
		if (start)
		{
			start = false;
			continue ;
		}
		else if (isEqual(tmp.first, d)) return tmp.second;
		++itr;
		if (itr != _db.end())
		{
			next = *itr;
			if (isBigger(next.first, tmp.first) && isSmaller(next.first, d))
			{
				out = next.second;
			}
		}
	}
	return (out);
}

void	BitcoinExchange::printValue(std::pair<std::string, float> query) const
{
	(void)query;
	std::cout << query.first << " => ";
	std::cout << query.second << " = ";
	std::cout << query.second * findValue(query.first) << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}