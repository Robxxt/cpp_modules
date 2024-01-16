/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 02:24:02 by rdragan          ###   ########.fr       */
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

void	combineSortedArrays(std::vector< std::pair<int, int> >& lst, int l, int m, int r)
{
	int	leftLen = m - l + 1;
	int	rightLen = r - m;
	std::vector< std::pair<int, int> > leftCopy(leftLen);
	std::vector< std::pair<int, int> > rightCopy(rightLen);
	int	i, j, k;

	for (int i = 0; i < leftLen; i++) leftCopy[i] = lst[l + i];
	for (int i = 0; i < rightLen; i++) rightCopy[i] = lst[i + m + 1];
	for (i = 0, j = 0, k = l; i < leftLen && j < rightLen; k++)
	{
		if (leftCopy[i].first <= rightCopy[j].first) lst[k] = leftCopy[i++];
		else lst[k] = rightCopy[j++];
	}
	/* If there are any items from leftCopy or rightCopy insert them in the lst */
	while (i < leftLen) lst[k++] = leftCopy[i++];
	while (j < rightLen) lst[k++] = rightCopy[j++];
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
		std::vector<int> lst = readInput(argc, argv);
		PmergeMe program(lst);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << '\n';
	}
}