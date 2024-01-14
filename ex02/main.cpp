/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/14 01:50:21 by rdragan          ###   ########.fr       */
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

void	printList(std::vector<int> lst)
{
	for (std::vector<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout << *itr << std::endl;
}

template <typename T>
void	merge_sorted_arrays(T a, int l, int m, int r)
{
	int	left_length = m - l + 1;
	int	right_length = r - m;
	int	temp_left[left_length];
	int	temp_right[right_length];
	int	i, j, k;

	for (int i = 0; i < left_length; i++) temp_left[i] = a[l + i];
	for (int i = 0; i < right_length; i++) temp_right[i] = a[m + 1 + i];
	for (i = 0, j = 0, k = 0; k <= r; k++)
	{
		if ((i < left_length) &&
			((j >= right_length) || temp_left[i] < temp_right[j]))
		{
			a[k] = temp_left[i];
			i++;
		}
		else a[k] = temp_right[j++];
	}
}

template <typename T>
void	merge_sort_recursion(T a, int l, int r)
{
	if (l < r)
	{
		int	m = l + (r - l) / 2;
		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, l);
		merge_sorted_arrays(a, l, m, r);
	}
}

template <typename T>
void	merge_sort(T a, int length)
{
	merge_sort_recursion(a, 0, length - 1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	tmp[] = {9,4,8,1,7,0,3,2,5,6};
	std::vector<int>	array;
	int length = 10;
	for (int i = 0; i < length; i++) array.push_back(tmp[i]);
	
	merge_sort(array, length);
	for (int i = 0; i < length; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
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