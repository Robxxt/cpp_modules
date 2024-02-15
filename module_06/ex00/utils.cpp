/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:53:36 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/14 10:56:24 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

bool	isSpecial(const std::string& s)
{
	return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf" || s == "+inff" || s == "-inff" || s == "inff");
}

void	printSpecial(const std::string& s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (s == "+inf" || s == "-inf" || s == "inf" || s == "+inff" || s == "-inff" || s == "inff")
		std::cout << s;
	else
		std::cout << s << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (s == "+inf" || s == "-inf" || s == "inf" || s == "+inff" || s == "-inff" || s == "inff")
		std::cout << s;
	else
		std::cout << s;
	std::cout << std::endl;
}

void	printFromChar(const std::string& s)
{
	std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << s << std::endl;
	std::cout << "float: " << s << ".0" << "f" << std::endl;
	std::cout << "double: " << s << ".0" << std::endl;
}

void	printFromFloat(const std::string& s)
{
	float	d = static_cast<double>(strtod(s.c_str(), NULL));
	float f = static_cast<float>(d);
	
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << static_cast<char>(d);
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
	std::cout << "float: ";
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
}

void	printFromDouble(const std::string& s)
{
	double	d = static_cast<double>(strtod(s.c_str(), NULL));
	float f = static_cast<float>(d);
	
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << static_cast<char>(d);
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
	std::cout << "float: ";
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
}

void	printFromInt(const std::string& s)
{
	int	d = static_cast<int>(strtod(s.c_str(), NULL));
	float f = static_cast<float>(d);
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << static_cast<char>(d);
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
	std::cout << "float: ";
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
}


bool	inputIsFloatFormat(const std::string& s)
{
	bool	hasADot = false;
	for (int i = 0; i < static_cast<int>(s.length() - 1); i++)
	{
		if (i == 0 && (s[0] == '-' || s[0] == '+'))
			continue ;
		if (std::isdigit(s[i]) == false && hasADot == false && s[i] == '.')
			hasADot = true;
		else if (std::isdigit(s[i]) == false)
			return false;
	}
	return true;
}

bool	inputIsDoubleFormat(const std::string& s)
{
	bool	hasADot = false;
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if (i == 0 && (s[0] == '-' || s[0] == '+'))
			continue ;
		if (std::isdigit(s[i]) == false && hasADot == false && s[i] == '.')
			hasADot = true;
		else if (std::isdigit(s[i]) == false)
			return false;
	}
	return true;
}

bool	inputIsIntFormat(const std::string& s)
{
	for (int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if (i == 0 && (s[0] == '-' || s[0] == '+'))
			continue ;
		if (std::isdigit(s[i]) == false)
			return false;
	}
	return true;
}