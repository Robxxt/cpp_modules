/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:10:42 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 01:53:44 by rdragan          ###   ########.fr       */
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

// void	test_valid_item(const std::string& s, bool expect)
// {
// 	std::cout << ((valid_item(s) == expect) ? "[ok]" : ("[ko]: " + s)) << std::endl;
// }

// void	test()
// {
// 	test_valid_item("+", true);
// 	test_valid_item("+1", false);
// 	test_valid_item("-", true);
// 	test_valid_item("-2", false);
// 	test_valid_item("10", false);
// 	test_valid_item("9", true);
// 	test_valid_item("12", false);
// 	test_valid_item("*2", false);
// 	test_valid_item("*", true);
// 	test_valid_item("/", true);
// 	test_valid_item("`", false);
// 	test_valid_item("^", false);
// 	test_valid_item("--", false);
// }

int	main(int argc, char **argv)
{
	// test();
	if (argc != 2)
	{
		std::cerr << ((argc == 1) ? "[ERROR]: You must provide one argument!" : "[ERROR]: Too many arguments!") << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << std::endl;
	}
}