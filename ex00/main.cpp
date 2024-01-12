/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:09 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/12 02:43:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float	getFloat(const std::string& s)
{
	std::istringstream	iss(s);
	float				result;
	bool				start = true;
	
	iss >> result;
	if (s[0] == '\0')
		throw std::invalid_argument("expected a number");
	for (std::string::const_iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		if (start && (*itr == '+' || *itr == '-'))
		{
			start = false;
			++itr;
		}
		if (!std::isdigit(*itr) && *itr != '.')
			throw std::invalid_argument("expected a number");
	}
	return (result);
}

bool	isValidFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	return (file.good());
}

void	testCase(const std::string& s)
{
	try
	{
		std::cout << "> " << getFloat(s) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// BitcoinExchange::Date d("1999-12-09");
	testCase("123");
	testCase("+");
	testCase("-");
	testCase("-1");
	testCase("-0");
	testCase("123.12");
	testCase("123.0");
	testCase("123.a");
	testCase("-1234");
	testCase("123av");
	testCase("ac123av");
	testCase("");
	// if (argc != 2 || !isValidFile(argv[1]))
	// {
	// 	std::cerr << "Error: could not open file" << std::endl;
	// }
	// else
	// {
	// 	std::cout << "You can read from the file" << std::endl;
	// 	BitcoinExchange btc(argv[1]);
	// }
	return (0);
}