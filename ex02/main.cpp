/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/15 17:40:26 by rdragan          ###   ########.fr       */
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

void	printList(std::vector< std::pair<int, int> >& lst)
{
	std::vector< std::pair<int, int> >::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout << "( " << (*itr).first << ", " << (*itr).second << " )" << std::endl;
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

void	mergeSort(std::vector< std::pair<int, int> >& lst, int l, int r)
{
	if (l < r)
	{
		int	m = l + (r - l) / 2;
		mergeSort(lst, l, m);
		mergeSort(lst, m + 1, r);
		combineSortedArrays(lst, l, m, r);
	}
}

void	binaryInsert(std::vector< std::pair<int, int> >& lst, int num)
{
	int	l = 0;
	int	r = lst.size() - 1;

	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (num == lst[m].first) break;
		if (num > lst[m].first) l = m + 1;
		else r = m - 1;
	}
	std::pair<int, int> tmp(num, -1);
	lst.insert(lst.begin() + l, tmp);
}

std::vector< std::pair<int, int> >	getPairArray(std::vector<int>& array)
{
	std::vector< std::pair<int, int> >	res;
	size_t								len = array.size();

	for (size_t i = 0; i < len - 1; i+=2)
	{
		std::pair<int, int>	tmp(array[i], array[i+1]);
		res.push_back(tmp);
	}
	if (len % 2 != 0)
	{
		std::pair<int, int>	tmp(array[len - 1], -1);
		res.push_back(tmp);
	}
	return res;
}

int	t(int k)
{
	return ((pow(2, k + 1) + pow(-1, k)) / 3);
}

void	insert(std::vector< std::pair<int, int> >& lst)
{
	std::vector< std::pair<int, int> >::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if ((*itr).second >= 0)
		{
			binaryInsert(lst, (*itr).second);
			++itr;
		}
	}
	
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	tmp[] = {9,44,8,1,7,0,3,2,5,6,25};
	std::vector<int>	array;
	int length = 11;
	for (int i = 0; i < length; i++) array.push_back(tmp[i]);
	
	std::vector< std::pair<int, int> > pairArray;
	pairArray = getPairArray(array);
	printList(pairArray);
	std::cout << "------------" << std::endl;
	binaryInsert(pairArray, 23);
	mergeSort(pairArray, 0, pairArray.size() - 1);
	insert(pairArray);
	printList(pairArray);
	std::cout << t(4) << std::endl;
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