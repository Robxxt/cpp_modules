/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:09 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 07:54:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float	getFloat(const std::string& s, bool maxThousend)
{
	std::istringstream	iss(s);
	float				result;
	
	iss >> result;
	if (s[0] == '\0')
		throw std::invalid_argument("expected a number.");
	for (std::string::const_iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		if (*itr == '-') throw std::invalid_argument("not a positive number.");
		if (!std::isdigit(*itr) && *itr != '.') throw std::invalid_argument("expected a number.");
	}
	if (maxThousend && result >= 1000)
		throw std::invalid_argument("too large a number");
	return (result);
}

bool	isValidFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	return (file.good());
}

std::pair<std::string, float>	parseDBLine(const std::string& s)
{
	std::istringstream	iss(s);
	std::string			tmp;
	std::string			dateString;
	std::string			valueString;
	int					i = 0;

	while (std::getline(iss, tmp, ','))
	{
		if (i == 0)
			dateString = tmp;
		else
			valueString = tmp;
		i++;
	}
	/* I call Date constructor just in case the date is invalid to throw the exception */
	Date	d(dateString);
	return std::pair<std::string, float>(dateString, getFloat(valueString, false));
}

std::pair<std::string, float>	parseLine(const std::string& s)
{
	std::istringstream	iss(s);
	std::string			dateString;
	std::string			valueString;
	char				placeholder;

	iss >> dateString >> placeholder >> valueString;
	/* I call Date constructor just in case the date is invalid to throw the exception */
	Date	d(dateString);
	return std::pair<std::string, float>(dateString, getFloat(valueString, true));
}

void	testCmp(std::string a, std::string b)
{
	Date A(a);
	Date B(b);

	std::cout << "[<] " << a << ", " << b << " => " << (A < B) << std::endl;
	std::cout << "[>] " << a << ", " << b << " => " << (A > B) << std::endl;
	std::cout << "[==] " << a << ", " << b << " => " << (A == B) << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// if (argc != 2 || !isValidFile(argv[1]))
	// {
	// 	std::cerr << "Error: could not open file" << std::endl;
	// }
	// else
	// {
	// 	try
	// 	{
	// 		BitcoinExchange btc(argv[1]);
	// 		// btc.makeQuery();
	// 		btc.findValue("2011-01-03");
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// }
	testCmp("2012-05-25", "2012-06-25");
	testCmp("2012-06-25", "2012-06-24");
	testCmp("2012-06-25", "2012-06-25");
	testCmp("2015-06-25", "2012-06-24");
	testCmp("2009-06-25", "2012-06-24");
	return (0);
}