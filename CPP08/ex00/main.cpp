/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:17:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 12:09:13 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.h"

template <typename T>
void	fill_list(T& myList)
{
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}
}

template <typename T>
void	print_list(T myList)
{
	typename T::iterator it;

	for (it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	testOneValue(T& lst, int value)
{
	int	res;
	try
	{
		res = easyfind(lst, value);
		std::cout << "FOUND: " << res << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

template <typename T>
void	testEasyFind(T& lst)
{
	testOneValue(lst, 1);
	testOneValue(lst, 4);
	testOneValue(lst, 7);
	testOneValue(lst, 15);
	testOneValue(lst, 10);
}

int	main()
{
	std::list<int> myList;

	fill_list(myList);
	print_list(myList);
	testEasyFind(myList);
	return (0);
}