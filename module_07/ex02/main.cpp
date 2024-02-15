/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:51:45 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/26 16:07:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

void	testExceptionOutOfIndex()
{
	Array<double> n1(3);

	std::cout << "testExceptionOutOfIndex" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Modify out of index: ";
	try
	{
		n1[4] = 10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Modify in valid range: ";
	n1[1] = 42.42;
	std::cout << "New value set to " << n1[1] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void	testSize()
{
	Array<int>n1(10);
	Array<float>n2(4);

	std::cout << "testSize" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "size of Array<int>n1(10) = " << n1.size() << std::endl;
	std::cout << "size of Array<float>n2(4) = " << n2.size() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void	testCopyConstructor()
{
	int	arr_size = 3;
	Array<int> n1(arr_size);
	Array<int> n2(n1);
	

	std::cout << "testCopyConstructor" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout<< "Before" << std::endl;
	std::cout<< "n1: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n1[i] << "\t";
	std::cout << std::endl << "n2: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n2[i] << "\t";
	std::cout << std::endl << "After modifying n1" << std::endl;
	n1[2] = 2424;
	std::cout << "n1: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n1[i] << "\t";
	std::cout << std::endl << "n2: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n2[i] << "\t";
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void	testAssignmentOperator()
{
	int	arr_size = 3;
	Array<int> n1(arr_size);
	Array<int> n2 = n1;
	

	std::cout << "testAssignmentOperator" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout<< "Before" << std::endl;
	std::cout<< "n1: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n1[i] << "\t";
	std::cout << std::endl << "n2: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n2[i] << "\t";
	std::cout << std::endl << "After modifying n1" << std::endl;
	n1[2] = 2424;
	std::cout << "n1: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n1[i] << "\t";
	std::cout << std::endl << "n2: " << std::endl;
	for (int i = 0; i < arr_size; i++)
		std::cout << i << ": "<< n2[i] << "\t";
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

int	main(void)
{
	testCopyConstructor();
	testAssignmentOperator();
	testExceptionOutOfIndex();
	testSize();
	return (0);
}