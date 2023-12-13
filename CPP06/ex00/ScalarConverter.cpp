/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 11:53:04 by rdragan          ###   ########.fr       */
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
	char	*end;
	double	nDouble = static_cast<double>(strtod(s.c_str(), &end));
	if (*end != '\0')
	{
		std::cerr << "Failed conversion " << nDouble << std::endl;
		return ;
	}
	float	nFloat = static_cast<float>(nDouble);
	long	nLong = static_cast<long>(nDouble);

	std::cout << "char: ";
	if ((nLong > std::numeric_limits<int>::max()) || nLong < std::numeric_limits<int>::min())
	{
		std::cout << "impossible";
	}
	else if (nLong >= 32 && nLong <= 126)
	{
		std::cout << static_cast<char>(nLong);
	}
	else
	{
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
	std::cout << "int: ";
	if ((nLong > std::numeric_limits<int>::max()) || nLong < std::numeric_limits<int>::min())
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << static_cast<int>(nLong);
	}
	std::cout << std::endl;
	
	std::cout << nDouble << std::endl;
	std::cout << nFloat << std::endl;
	std::cout << nLong << std::endl;
}