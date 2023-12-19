/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:28:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 13:12:04 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <string>

int	main(void)
{
	Span	s1;
	Span	s2(3);
	Span	s3 = s2;

	s2.addNumber(1);
	s2.addNumber(1);
	s2.addNumber(1);
	s2.addNumber(1);
	s2.print();
	return (0);
}