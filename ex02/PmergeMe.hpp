/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:41:39 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 17:46:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe& p);
	PmergeMe& operator=(const PmergeMe& p);
public:
	PmergeMe(std::vector<int>);
	~PmergeMe();
};

#endif