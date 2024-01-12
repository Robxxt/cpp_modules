/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:15 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 05:34:17 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <ctime>
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
		bool	isValid() const;
		~Date();
};
class BitcoinExchange
{
private:
	std::map<Date, float>	_db;
	std::string				_inputFile;
	// Make a map
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& b); // IMPLEMENT LATER
	BitcoinExchange&	operator=(const BitcoinExchange& b); // IMPLEMENT LATER
public:
	
	BitcoinExchange(const std::string& s);
	~BitcoinExchange();
	void printValue() const;
	void	makeQuery() const;
};

bool	isValidFile(const std::string& fileName);
float	getFloat(const std::string& s, bool maxThousend);
std::pair<std::string, float>	parseDBLine(const std::string& s);
std::pair<std::string, float>	parseLine(const std::string& s);

#endif