/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:15 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 01:20:09 by rdragan          ###   ########.fr       */
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

class BitcoinExchange
{
private:
	// Make a map
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& b); // IMPLEMENT LATER
	BitcoinExchange&	operator=(const BitcoinExchange& b); // IMPLEMENT LATER
public:
	BitcoinExchange(const std::string& s);
	~BitcoinExchange();
	class	Date
	{
		private:
			int	_year;
			int	_month;
			int	_day;
			Date();
			Date(const Date& d);
			Date& operator=(const Date& d);
		public:
			Date(const std::string& s);
			bool	isValid() const;
			~Date();
	};
};




#endif