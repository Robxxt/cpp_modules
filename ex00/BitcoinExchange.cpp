/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 04:35:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date() { throw std::runtime_error("Forbidden to initialize Date with default constructor"); }

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
	if (_year < d._year)
		return true;
	if (_month < d._month)
		return true;
	if (_day < d._day)
		return true;
	return false;
}

bool	Date::operator>(const Date& d) const
{
	if (_year > d._year)
		return true;
	if (_month > d._month)
		return true;
	if (_day > d._day)
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
}

void	BitcoinExchange::makeQuery()
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
				tmp = parseLine(line, true);
				toPrint = true;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				toPrint = false;
			}
			if (toPrint) std::cout << tmp.first << ", " << tmp.second << std::endl;

			// std::cout << line << std::endl;
		}
		else
			head = false;
	}
}

BitcoinExchange::~BitcoinExchange() {}