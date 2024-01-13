/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 18:06:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <cstdlib>

bool	isValidNumber(const std::string& in)
{

	for (size_t i = 0; i < in.length(); i++)
	{
		if (!std::isdigit(in[i])) return false;
	}
	return true;
}

std::vector<int>	readInput(int argc, char **argv)
{
	std::vector<int>	v;
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i])) throw std::invalid_argument("The list has an invalid item.");
		v.push_back(atoi(argv[i]));
	}
	return v;
}

void	printList(std::vector<int> lst)
{
	for (std::vector<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout << *itr << std::endl;
}

void	testNumber(const std::string& n, bool expect)
{
	std::cout << ((isValidNumber(n) == expect) ? "[OK]" : "[KO]: " + n) << std::endl;
}

void	test()
{
	testNumber("1", true);
	testNumber("123", true);
	testNumber("-123", false);
	testNumber("-1", false);
	testNumber("a1", false);
	testNumber("1a", false);
	testNumber("a", false);
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cerr << "[ERROR]: There's nothing to sort :(" << std::endl;
		return (0);
	}
	try
	{
		(void)argv[1];
		std::vector<int> lst = readInput(argc, argv);
		PmergeMe program(lst);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << '\n';
	}
	
}