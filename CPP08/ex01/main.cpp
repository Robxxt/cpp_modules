/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:28:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 14:29:59 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <string>

void	testPdfCase()
{
	std::cout << "testPdfCase" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	TestAddMultipleConsecutiveNumbers()
{
	std::cout << "TestAddMultipleConsecutiveNumbers" << std::endl;

	std::cout << "--------------------------------" << std::endl;
	Span	a(5);
	std::cout << "Before calling the function" << std::endl;
	a.print();
	std::cout << std::endl;
	std::cout << "After calling the function" << std::endl;
	a.addMultipleConsecutiveNumbers(5);
	a.print();
	std::cout << "--------------------------------" << std::endl;
}

int	main(void)
{
	testPdfCase();
	TestAddMultipleConsecutiveNumbers();
	return (0);
}