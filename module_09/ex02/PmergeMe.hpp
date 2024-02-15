/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:41:39 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 04:21:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <stdexcept>
# include <cmath>
# include <ctime>
# include <iomanip>

class PmergeMe
{
private:
	clock_t				_startTime;
	clock_t				_finalTime;
	double				_totalTime;
	std::vector<int>	_array;
	std::vector<int>	_arrayA;
	std::vector<int>	_arrayB;
	std::vector< std::pair<int, int> > _pairArray;
	std::deque<int>						_deque;
	std::deque<int>						_dequeA;
	std::deque<int>						_dequeB;
	std::deque< std::pair<int, int> > _pairDeque;
	PmergeMe();
	PmergeMe(const PmergeMe& p);
	PmergeMe& operator=(const PmergeMe& p);
public:
	PmergeMe(const std::vector<int>& vect, const std::deque<int>& deq);
	~PmergeMe();
	/* Functions for vectors */
	void	printArray(const std::vector<int>& arr);
	void	getPairArray();
	void	getTwoArrays();
	void	binaryInsertionSort(int num);
	void	mergeSort(int l, int r);
	void	combineSortedArrays(int l, int m, int r);
	void	insertBatch(size_t tk, size_t lastBIndex);
	void	insertVector();
	void	sortWithVector();
	/* Functions for deques */
	void	printDeque(const std::deque<int>& arr);
	void	getPairDeque();
	void	getTwoDeques();
	void	binaryInsertionSortDeque(int num);
	void	mergeSortDeque(int l, int r);
	void	insertDeque();
	void	sortWithDeque();
	void	insertBatchDeque(size_t tk, size_t lastBIndex);
	void	combineSortedDeques(int l, int m, int r);
};

int		t(int k);
#endif