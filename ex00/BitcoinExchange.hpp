/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:15 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/03 02:45:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
private:
	BitcoinExchange();
public:
	BitcoinExchange(const std::string& s);
	BitcoinExchange(const BitcoinExchange& b); // IMPLEMENT LATER
	// BitcoinExchange&	BitcoinExchange(const BitcoinExchange& b); // IMPLEMENT LATER
	~BitcoinExchange();
};




#endif