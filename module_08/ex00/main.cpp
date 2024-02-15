/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:00:55 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/26 19:48:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <list>
#include <vector>
#include <iostream>

void	initList(std::list<int>& lst)
{
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
}

void	initVector(std::vector<int>& lst)
{
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
}


template <typename T>
void	testOne(T& lst, int n)
{
	int	val;
	try
	{
		val = easyFind(lst, n);
		std::cout << "FOUND: " <<  val << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << n << " " << e.what() << '\n';
	}
}

void	testList()
{
	std::list<int>lst;
	std::cout << "testList" << std::endl;
	initList(lst);
	std::cout << "------------------" << std::endl;
	testOne(lst, 10);
	testOne(lst, 11);
	testOne(lst, 20);
	testOne(lst, 30);
	testOne(lst, 31);
	std::cout << "------------------" << std::endl;
}

void	testVector()
{
	std::vector<int>lst;

	std::cout << "testVector" << std::endl;
	std::cout << "------------------" << std::endl;
	initVector(lst);
	testOne(lst, 10);
	testOne(lst, 11);
	testOne(lst, 20);
	testOne(lst, 30);
	testOne(lst, 31);
	std::cout << "------------------" << std::endl;
}

int	main()
{
	testList();
	testVector();

	return (0);
}