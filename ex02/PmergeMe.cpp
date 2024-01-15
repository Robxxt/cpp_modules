/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:44:48 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 00:34:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& lst)
{
	if (hasDuplicates(lst)) throw std::invalid_argument("Repeated values");
	_array = lst;
	_pairArray = getPairArray(_array);
	mergeSort(_pairArray, 0, _pairArray.size() - 1);
	_arrayA = getListA(_pairArray);
	_arrayB = getListB(_pairArray);
	insertLastOdd(_array, _arrayB);
	insert(_arrayA, _arrayB);
	printList(_arrayA);
}

PmergeMe::~PmergeMe()
{
}
