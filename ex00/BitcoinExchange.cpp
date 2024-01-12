/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 03:58:50 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date(const std::string& s)
{
	std::istringstream iss(s);
    char dash;

    iss >> _year >> dash >> _month >> dash >> _day;
	if (isValid() == false)
		throw std::invalid_argument("bad input => " + s);
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

BitcoinExchange::BitcoinExchange(const std::string& b)
{
	std::ifstream	fileName(b);
	std::string		line;
	bool			head = true;
	std::pair<std::string, float> tmp;

	while (std::getline(fileName, line))
	{
		if (head == false)
		{
			// Store in a map
			try
			{
				tmp = parseLine(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
			}
			std::cout << tmp.first << ", " << tmp.second << std::endl;
			// std::cout << line << std::endl;
		}
		else
			head = false;
	}
}

BitcoinExchange::~BitcoinExchange() {}