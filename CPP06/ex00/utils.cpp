/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:53:36 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 16:21:53 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

void	display_one_char(const std::string& s)
{
	char	nChar = static_cast<char>(s[0]);
	int	nInt = static_cast<int>(s[0]);
	float	nFloat = static_cast<float>(s[0]);
	double	nDouble = static_cast<double>(s[0]);

	std::cout << "char: " << nChar << std::endl;
	std::cout << "int: " << nInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nFloat << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << nDouble << std::endl;
}

bool	isSpecial(const std::string& s)
{
	return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf");
}

void	printSpecial(const std::string& s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (s == "inf" || s == "-inf" || s == "+inf")
		std::cout << "impossible";
	else
		std::cout << s << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (s == "inf" || s == "-inf" || s == "+inf")
		std::cout << "impossible";
	else
		std::cout << s;
	std::cout << std::endl;
}

void	printNormal(const std::string& s)
{
	char	*end;
	double	nDouble = static_cast<double>(strtod(s.c_str(), &end));
	float	nFloat = static_cast<float>(nDouble);
	long	nLong = static_cast<long>(nDouble);

	std::cout << "char: ";
	if ((nLong > std::numeric_limits<int>::max()) || nLong < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else if (nLong >= 32 && nLong <= 126)
		std::cout << static_cast<char>(nLong);
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: ";
	if ((nLong > std::numeric_limits<int>::max()) || nLong < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(nLong);
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: ";
	std::cout << nFloat << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: ";
	std::cout << nDouble << std::endl;
}

bool	inputIsFloatFormat(const std::string& s)
{
	bool	hasADot = false;
	for (int i = 0; i < static_cast<int>(s.length() - 1); i++)
	{
		if (std::isdigit(s[i]) == false && hasADot == false && s[i] == '.')
			hasADot = true;
		else if (std::isdigit(s[i]) == false)
			return false;
	}
	return true;
}