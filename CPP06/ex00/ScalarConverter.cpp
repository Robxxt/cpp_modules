/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/10 10:54:26 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) { (void)s; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s)
{
	(void)s;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& s)
{
	std::cout << "Converting " << s << " ..." << std::endl;
}