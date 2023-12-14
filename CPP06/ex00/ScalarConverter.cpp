/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/14 10:42:34 by rdragan          ###   ########.fr       */
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

void	ScalarConverter::convert(std::string s)
{
	if (isSpecial(s) == true)
		printSpecial(s);
	else if (s.length() == 1)
		printFromChar(s);
	else if (inputIsIntFormat(s))
		printFromInt(s);
	else if (inputIsDoubleFormat(s))
		printFromDouble(s);
	else if (inputIsFloatFormat(s))
		printFromFloat(s);
	else
		std::cerr << "[ERROR] INVALID INPUT" << std::endl;
}