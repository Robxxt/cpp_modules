/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:44:48 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 03:17:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& lst)
{
	_array = lst;
	std::cout << "Before: ";
	printArray(_array);
	getPairArray();
	mergeSort(0, _pairArray.size() - 1);
	getTwoArrays();
	insert();
	std::cout << "After: ";
	printArray(_arrayA);
	_totalTime = static_cast<double>((_finalTime - _startTime)) / CLOCKS_PER_SEC;
	std::cout <<  "Time to process a range of " << _array.size() << " elements with std::vector<int> : ";
	std::cout << std::fixed << std::setprecision(5) << _totalTime << "s" << std::endl;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printArray(const std::vector<int>& arr)
{
	std::vector<int>::const_iterator itr;
	for (itr = arr.begin(); itr != arr.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void	PmergeMe::getPairArray()
{
	size_t								len = _array.size();
	std::pair<int, int>					tmp;

	_startTime = clock();
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
		insertBatch(tOut, lastBIndex + 1);
		lastBIndex = tOut;
		k++;
	} while (lastBIndex < lstBLen && tOut <= lstBLen);
	_finalTime = clock();
}

void	PmergeMe::insertBatch(size_t tk, size_t lastBIndex)
{
	size_t	len = _arrayB.size();
	size_t	i = (tk >= len) ? len - 1 : tk;
	for (; i >= lastBIndex; i--) binaryInsertionSort(_arrayB[i]);
}

void	PmergeMe::mergeSort(int l, int r)
{
	if (l < r)
	{
		int	m = l + (r - l) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		combineSortedArrays(l, m, r);
	}
}

void	PmergeMe::binaryInsertionSort(int num)
{
	int	l = 0;
	int	r = _arrayA.size() - 1;

	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (num > _arrayA[m]) l = m + 1;
		else r = m - 1;
	}
	_arrayA.insert(_arrayA.begin() + l, num);
}

void	PmergeMe::combineSortedArrays(int l, int m, int r)
{
	int	leftLen = m - l + 1;
	int	rightLen = r - m;
	std::vector< std::pair<int, int> > leftCopy(leftLen);
	std::vector< std::pair<int, int> > rightCopy(rightLen);
	int	i, j, k;

	for (int i = 0; i < leftLen; i++) leftCopy[i] = _pairArray[l + i];
	for (int i = 0; i < rightLen; i++) rightCopy[i] = _pairArray[i + m + 1];
	for (i = 0, j = 0, k = l; i < leftLen && j < rightLen; k++)
	{
		if (leftCopy[i].first <= rightCopy[j].first) _pairArray[k] = leftCopy[i++];
		else _pairArray[k] = rightCopy[j++];
	}
	/* If there are any items from leftCopy or rightCopy insert them in the _pairArray */
	while (i < leftLen) _pairArray[k++] = leftCopy[i++];
	while (j < rightLen) _pairArray[k++] = rightCopy[j++];
}