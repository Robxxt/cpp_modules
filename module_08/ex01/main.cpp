/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:06:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/27 13:12:37 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

void	fill(int* arr)
{
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = i + 1;
	}
}

void	testSpan()
{
	Span sp = Span(10000);
	int	i[10000];

	std::cout << "testSpan" << std::endl;
	std::cout << "_________________" << std::endl;
	fill(i);
	sp.addNumbers(i, i + 10000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "_________________" << std::endl;
}

void	testPdfCase()
{
	Span sp = Span(5);
	std::cout << "testPdfCase" << std::endl;
	std::cout << "_________________" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "_________________" << std::endl;
}

int	main()
{
	testPdfCase();
	testSpan();
	return (0);
}