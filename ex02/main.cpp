/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/14 05:02:10 by rdragan          ###   ########.fr       */
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

void	combineSortedArrays(std::vector<int>& lst, int l, int m, int r)
{
	int	leftLen = m - l + 1;
	int	rightLen = r - m;
	std::vector<int> leftCopy(leftLen);
	std::vector<int> rightCopy(rightLen);
	int	i, j, k;

	for (int i = 0; i < leftLen; i++) leftCopy[i] = lst[l + i];
	for (int i = 0; i < rightLen; i++) rightCopy[i] = lst[i + m + 1];
	for (i = 0, j = 0, k = l; i < leftLen && j < rightLen; k++)
	{
		if (leftCopy[i] <= rightCopy[j]) lst[k] = leftCopy[i++];
		else lst[k] = rightCopy[j++];
	}
	/* If there are any items from leftCopy or rightCopy insert them in the lst */
	while (i < leftLen) lst[k++] = leftCopy[i++];
	while (j < rightLen) lst[k++] = rightCopy[j++];
}

void	mergeSort(std::vector<int>& lst, int l, int r)
{
	if (l < r)
	{
		int	m = l + (r - l) / 2;
		mergeSort(lst, l, m);
		mergeSort(lst, m + 1, r);
		combineSortedArrays(lst, l, m, r);
	}
}

void	binaryInsert(std::vector<int>& lst, int num)
{
	int	l = 0;
	int	r = lst.size() - 1;

	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (num == lst[m]) break;
		if (num > lst[m]) l = m + 1;
		else r = m - 1;
	}
	lst.insert(lst.begin() + l, num);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	tmp[] = {9,44,8,1,7,0,3,2,5,6};
	std::vector<int>	array;
	int length = 10;
	for (int i = 0; i < length; i++) array.push_back(tmp[i]);
	
	mergeSort(array, 0, array.size() - 1);
	std::cout << array.size() << std::endl;
	binaryInsert(array, 47);
	binaryInsert(array, 4);
	binaryInsert(array, 4);
	std::cout << array.size() << std::endl;
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	// if (argc <= 2)
	// {
	// 	std::cerr << "[ERROR]: There's nothing to sort :(" << std::endl;
	// 	return (0);
	// }
	// try
	// {
	// 	std::vector<int> lst = readInput(argc, argv);
	// 	PmergeMe program(lst);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "[ERROR]: " << e.what() << '\n';
	// }
	
}