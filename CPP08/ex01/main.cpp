/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:28:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 15:14:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	testAssignmentOverload()
{
	std::cout << "testAssignmentOverload" << std::endl;

	std::cout << "--------------------------------" << std::endl;
	Span	a(5);
	Span	b = a;
	std::cout << "A list: " << std::endl;
	a.addRange(5);
	a.print();
	std::cout << "B list: " << std::endl;
	b.addRange(5);
	b.print();
	std::cout << "--------------------------------" << std::endl;
}

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

void	testShortAndLongSpan()
{
	std::cout << "testShortAndLongSpan" << std::endl;

	std::cout << "--------------------------------" << std::endl;
	Span	a(10000);
	std::cout << "Before calling the function" << std::endl;
	a.print();
	std::cout << std::endl;
	std::cout << "After calling the function" << std::endl;
	a.addRange(10000);
	std::cout << "shortestSpan: " << a.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << a.longestSpan() << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

int	main(void)
{
	testPdfCase();
	testShortAndLongSpan();
	testAssignmentOverload();
	return (0);
}