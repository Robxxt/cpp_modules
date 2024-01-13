/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:10:42 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 02:39:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

/*
I don't consider "-2" as a valid number.
*/
bool	valid_item(const std::string& item)
{
	if (item.length() > 1) return false;
	if (!std::isdigit(item[0]))
	{
		if (item[0] != '-' && item[0] != '+' && item[0] != '*' && item[0] != '/') return (false);
	}
	return (true);
}

int	operation(char o, int num[2])
{
	if (o == '+') return num[0] + num[1];
	if (o == '-') return num[0] - num[1];
	if (o == '*') return num[0] * num[1];
	if (o == '/') return num[0] / num[1];
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ((argc == 1) ? "[ERROR]: You must provide one argument!" : "[ERROR]: Too many arguments!") << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn(argv[1]);
		rpn.displayResult();
	}
	catch (const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << std::endl;
	}
}