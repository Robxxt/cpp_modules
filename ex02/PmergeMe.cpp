/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:44:48 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 01:49:03 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& lst)
{
	_array = lst;
	getPairArray();
	mergeSort(_pairArray, 0, _pairArray.size() - 1);
	getTwoArrays();
	insert();
	printList();
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printList()
{
	std::vector<int>::iterator itr;
	for (itr = _arrayA.begin(); itr != _arrayA.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void	PmergeMe::getPairArray()
{
	size_t								len = _array.size();
	std::pair<int, int>					tmp;
	for (size_t i = 0; i < len - 1; i+=2)
	{
		if (_array[i] > _array[i + 1])
		{
			std::pair<int, int>	tmp(_array[i], _array[i+1]);
			_pairArray.push_back(tmp);
		}
		else
		{
			std::pair<int, int>	tmp(_array[i+1], _array[i]);
			_pairArray.push_back(tmp);
		}
	}
}

void	PmergeMe::getTwoArrays()
{
	std::vector< std::pair<int, int> >::iterator	itr;

	for (itr = _pairArray.begin(); itr != _pairArray.end(); ++itr)
	{
		_arrayA.push_back((*itr).first);
		_arrayB.push_back((*itr).second);
	}
}

void	PmergeMe::insert()
{
	_arrayA.insert(_arrayA.begin(), _arrayB[0]);

	size_t	lstBLen = _arrayB.size();
	size_t	lastBIndex = 0;
	size_t	k = 2;
	size_t	tOut;

	size_t	len = _array.size();

	if (len % 2 != 0) _arrayB.push_back(_array[len - 1]);
	do
	{
		tOut = t(k);
		insertBatch(_arrayA, _arrayB, tOut, lastBIndex + 1);
		lastBIndex = tOut;
		k++;
	} while (lastBIndex < lstBLen && tOut <= lstBLen);
}