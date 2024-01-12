/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:15 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 10:09:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cctype>
# include <sstream>
# include <stdexcept>

class	Date
{
	private:
		int	_year;
		int	_month;
		int	_day;
	public:
		Date();
		Date(const std::string& s);
		Date(const Date& d);
		Date&	operator=(const Date& d);
		bool	operator<(const Date& d) const;
		bool	operator>(const Date& d) const;
		bool	operator==(const Date& d) const;
		bool	isValid() const;
		~Date();
};

class BitcoinExchange
{
private:
	std::map<std::string, float>	_db;
	std::string						_inputFile;
	// Make a map
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& b); // IMPLEMENT LATER
	BitcoinExchange&	operator=(const BitcoinExchange& b); // IMPLEMENT LATER
public:
	
	BitcoinExchange(const std::string& s);
	~BitcoinExchange();
	void 	printValue(std::pair<std::string, float> query) const;
	void	makeQuery() const;
	bool	isBigger(const std::string& d1, const std::string& d2) const;
	bool	isSmaller(const std::string& d1, const std::string& d2) const;
	bool	isEqual(const std::string& d1, const std::string& d2) const;
	float	findValue(const std::string& d) const;
};

bool	isValidFile(const std::string& fileName);
float	getFloat(const std::string& s, bool maxThousend);
std::pair<std::string, float>	parseDBLine(const std::string& s);
std::pair<std::string, float>	parseLine(const std::string& s);

#endif