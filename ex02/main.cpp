/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 03:58:24 by rdragan          ###   ########.fr       */
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
	for (size_t i = 0; i < in.length(); i++) if (!std::isdigit(in[i])) return false;
	return true;
}

std::vector<int>	readInputVector(int argc, char **argv)
{
	std::vector<int>	v;
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i])) throw std::invalid_argument("The list has an invalid item.");
		v.push_back(atoi(argv[i]));
	}
	return v;
}

std::deque<int>	readInputDeque(int argc, char **argv)
{
	std::deque<int>	v;
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i])) throw std::invalid_argument("The list has an invalid item.");
		v.push_back(atoi(argv[i]));
	}
	return v;
}

int	t(int k) { return ((pow(2, k + 1) + pow(-1, k)) / 3) - 1; }

int	main(int argc, char **argv)
{	
	if (argc <= 2)
	{
		std::cerr << "[ERROR]: There's nothing to sort :(" << std::endl;
		return (0);
	}
	try
	{
		std::vector<int> ve = readInputVector(argc, argv);
		std::deque<int> de = readInputDeque(argc, argv);
		PmergeMe program(ve, de);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << '\n';
	}
}