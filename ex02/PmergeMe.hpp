/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:41:39 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/16 01:04:28 by rdragan          ###   ########.fr       */
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
};

void	printList(std::vector<int>& lst);
void	printPairedList(std::vector< std::pair<int, int> >& lst);
std::vector< std::pair<int, int> >	getPairArray(std::vector<int>& array);
void	combineSortedArrays(std::vector< std::pair<int, int> >& lst, int l, int m, int r);
void	mergeSort(std::vector< std::pair<int, int> >& lst, int l, int r);
std::vector<int>	getListA(std::vector< std::pair<int, int> >& lst);
std::vector<int>	getListB(std::vector< std::pair<int, int> >& lst);
void	insertLastOdd(std::vector<int>& initLst, std::vector<int>& lstB);
void	insert(std::vector<int>& lstA, std::vector<int>& lstB);

#endif