/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:41:39 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/15 18:08:25 by rdragan          ###   ########.fr       */
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
	PmergeMe();
	PmergeMe(const PmergeMe& p);
	PmergeMe& operator=(const PmergeMe& p);
public:
	PmergeMe(const std::vector<int>& lst);
	~PmergeMe();
};

void	printPairedList(std::vector< std::pair<int, int> >& lst);
void	combineSortedArrays(std::vector< std::pair<int, int> >& lst, int l, int m, int r);
void	mergeSort(std::vector< std::pair<int, int> >& lst, int l, int r);


#endif