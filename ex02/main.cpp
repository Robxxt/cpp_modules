/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 00:35:00 by rdragan          ###   ########.fr       */
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

void	printPairedList(std::vector< std::pair<int, int> >& lst)
{
	std::vector< std::pair<int, int> >::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout << "( " << (*itr).first << ", " << (*itr).second << " )" << std::endl;
}

void	printList(std::vector<int>& lst)
{
	std::vector<int>::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
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

std::vector< std::pair<int, int> >	getPairArray(std::vector<int>& array)
{
	std::vector< std::pair<int, int> >	res;
	size_t								len = array.size();
	std::pair<int, int>	tmp;
	for (size_t i = 0; i < len - 1; i+=2)
	{
		if (array[i] > array[i + 1])
		{
			std::pair<int, int>	tmp(array[i], array[i+1]);
			res.push_back(tmp);
		}
		else
		{
			std::pair<int, int>	tmp(array[i+1], array[i]);
			res.push_back(tmp);
		}
	}
	return res;
}

int	t(int k) { return ((pow(2, k + 1) + pow(-1, k)) / 3) - 1; }

std::vector<int>	getListA(std::vector< std::pair<int, int> >& lst)
{
	std::vector< std::pair<int, int> >::iterator	itr;
	std::vector<int>								res;

	for (itr = lst.begin(); itr != lst.end(); ++itr)
	{
		res.push_back((*itr).first);
	}
	return	res;
}

std::vector<int>	getListB(std::vector< std::pair<int, int> >& lst)
{
	std::vector< std::pair<int, int> >::iterator	itr;
	std::vector<int>								res;

	for (itr = lst.begin(); itr != lst.end(); ++itr)
	{
		res.push_back((*itr).second);
	}
	return	res;
}

void	insertBatch(std::vector<int>& lstA, std::vector<int>& lstB, size_t tk, size_t lastBIndex)
{
	size_t	len = lstB.size();
	size_t	i = (tk >= len) ? len - 1 : tk;
	(void)lstA;
	for (; i >= lastBIndex; i--) binaryInsert(lstA, lstB[i]);
}

void	insert(std::vector<int>& lstA, std::vector<int>& lstB)
{
	std::vector<int>::iterator itr;

	lstA.insert(lstA.begin(), lstB[0]);

	size_t	lstBLen = lstB.size();
	size_t	lastBIndex = 0;
	size_t	k = 2;
	size_t	tOut;

	// std::cout << "lstB len: " << lstBLen << std::endl;
	do
	{
		tOut = t(k);
		// std::cout << "t(lBI): " << tOut << std::endl;
		// std::cout << "lastIndexB: " << lastBIndex << std::endl;
		insertBatch(lstA, lstB, tOut, lastBIndex + 1);
		lastBIndex = tOut;
		k++;
	} while (lastBIndex < lstBLen && tOut <= lstBLen);
	// std::cout << "-------" << std::endl;
}

void	insertLastOdd(std::vector<int>& initLst, std::vector<int>& lstB)
{
	size_t	len = initLst.size();

	if (len % 2 != 0) lstB.push_back(initLst[len - 1]);
}

bool	hasDuplicates(const std::vector<int>& myList) {
    std::vector<int>::const_iterator it1, it2;

    for (it1 = myList.begin(); it1 != myList.end(); ++it1) {
        for (it2 = myList.begin(); it2 != myList.end(); ++it2) {
            if (it1 != it2 && *it1 == *it2) {
                return true;
            }
        }
    }

    return false;  // No duplicates found
}


int	main(int argc, char **argv)
{
	// (void)argc;
	// (void)argv;
	// int	tmp[] = {9,44,8,1,7,0,3,2,5,6,25,71,4,21,23,13,32,51};
	// std::vector<int>	array;
	// int length = sizeof(tmp) / sizeof(int);
	// for (int i = 0; i < length; i++) array.push_back(tmp[i]);
	
	// std::vector< std::pair<int, int> > pairArray;
	// pairArray = getPairArray(array);
	// printPairedList(pairArray);
	// std::cout << "------------" << std::endl;
	// mergeSort(pairArray, 0, pairArray.size() - 1);
	// // printPairedList(pairArray);
	// std::vector<int>	listA = getListA(pairArray);
	// std::vector<int>	listB = getListB(pairArray);
	// std::cout << "LIST: " << std::endl;
	// printList(array);
	// std::cout << "LIST A" << std::endl;
	// printList(listA);
	// std::cout << "----------" << std::endl;
	// /* check if odd and insert the last odd element to the end of b */
	// insertLastOdd(array, listB);
	// std::cout << "LIST B" << std::endl;
	// printList(listB);
	// insert(listA, listB);
	// std::cout << "----------" << std::endl;
	// std::cout << "LIST A" << std::endl;
	// printList(listA);
	
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