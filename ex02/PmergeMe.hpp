/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:41:39 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 01:56:33 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>
# include <cmath>

class PmergeMe
{
private:
	std::vector<int> _array;
	std::vector<int> _arrayA;
	std::vector<int> _arrayB;
	std::vector< std::pair<int, int> > _pairArray;
	PmergeMe();
	PmergeMe(const PmergeMe& p);
	PmergeMe& operator=(const PmergeMe& p);
public:
	PmergeMe(const std::vector<int>& lst);
	~PmergeMe();
	void	printList();
	void	getPairArray();
	void	getTwoArrays();
	void	insertBatch(size_t tk, size_t lastBIndex);
	void	insert();
};

void	combineSortedArrays(std::vector< std::pair<int, int> >& lst, int l, int m, int r);
void	mergeSort(std::vector< std::pair<int, int> >& lst, int l, int r);
void	binaryInsert(std::vector<int>& lst, int num);
int		t(int k);
#endif