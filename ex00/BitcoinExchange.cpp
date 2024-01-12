/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 08:00:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date() {}

Date::Date(const std::string& s)
{
	std::istringstream iss(s);
    char dash;

    iss >> _year >> dash >> _month >> dash >> _day;
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

bool	Date::operator<(const Date& d) const
{
	if (_year > d._year)
		return false;
	if (_month > d._month)
		return false;
	if (_day > d._day)
		return false;
	return true;
}

bool	Date::operator>(const Date& d) const
{
	if (_year < d._year)
		return false;
	if (_month < d._month)
		return false;
	if (_day < d._day)
		return false;
	return true;
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
	return (!(_year <= 0 || _month > 12 || _day > 31) && mktime(&date) != -1)? true : false;
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
	std::ifstream	fileName(_inputFile);
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

/**/
bool	BitcoinExchange::isBigger(const std::string& d1, const std::string& d2) const
{
	Date	date1(d1);
	Date	date2(d2);

	return (date1 > date2);
}

bool	BitcoinExchange::isSmaller(const std::string& d1, const std::string& d2) const
{
	Date	date1(d1);
	Date	date2(d2);

	return (date1 < date2);
}

bool	BitcoinExchange::isEqual(const std::string& d1, const std::string& d2) const
{
	Date	date1(d1);
	Date	date2(d2);

	return (date1 == date2);
}

/*
Returns the value of the date that is querried. If the date
is not in the db, searches the closes lower date.
*/
float	BitcoinExchange::findValue(const std::string& d) const
{
	(void)d;
	std::pair<std::string, float>	tmp;
	std::pair<std::string, float>	latest;
	bool							start = true;

	for	(std::map<std::string, float>::const_iterator itr = _db.begin(); itr != _db.end(); ++itr)
	{
		tmp = *itr;
		if (start)
		{
			latest = tmp;
			start = false;
			continue ;
		}
		// std::cout << tmp.first << std::endl;
		if (isBigger(tmp.first, latest.first) && isSmaller(tmp.first, d))  std::cout << tmp.first << std::endl;
		if (isEqual(tmp.first, d))
		{
			std::cout << tmp.first << ", " << tmp.second << std::endl;
			return tmp.second;
		}
	}
	return (0);
}

void	BitcoinExchange::printValue(std::pair<std::string, float> query) const
{
	(void)query;
	// std::cout << query.first << " => ";
	// std::cout << query.second << " = ";
	// std::cout << query.second * findValue(query.first) << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}