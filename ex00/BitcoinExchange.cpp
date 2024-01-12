/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 07:07:44 by rdragan          ###   ########.fr       */
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
		std::cout << tmp.first << ", " << tmp.second << std::endl;
		// std::cout << line << std::endl;
	}
	std::cout << _db.size() << std::endl;
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

/*
Returns the value of the date that is querried. If the date
is not in the db, searches the closes lower date.
*/
float	BitcoinExchange::findValue(const std::string& d) const
{
	(void)d;
	// Date	date(d);
	std::pair<Date, float>	tmp;

	// for	(std::map<Date, float>::const_iterator itr = _db.begin(); itr != _db.end(); ++itr)
	// {
	// 	tmp = *itr;
	// 	std::cout << tmp.second << std::endl;
	// }
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