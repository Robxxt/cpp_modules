/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:13 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 01:28:08 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::Date::Date(const std::string& s)
{
	std::istringstream iss(s);
    char dash;

    iss >> _year >> dash >> _month >> dash >> _day;
	if (isValid() == false)
		std::cout << "Not valid" << std::endl;
	else
		std::cout << "Valid" << std::endl;
}

bool	BitcoinExchange::Date::isValid() const
{
	tm date;
    
	/* tm_year is expecting this the years after 1900 */
    date.tm_year = _year - 1900;
	/* the months start at index 0 */
    date.tm_mon = _month - 1;
    date.tm_mday = _day;

    /*
	Try to convert the date to t_time. If it fails it means
	that the date is not valid.
	*/
	return (!(_month > 12 || _day > 31) && mktime(&date) != -1)? true : false;
}

BitcoinExchange::Date::~Date() {}

BitcoinExchange::BitcoinExchange(const std::string& b)
{
	std::ifstream	fileName(b);
	std::string		line;

	while (std::getline(fileName, line))
	{
		// Store in a map
		std::cout << line << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {}