/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:57:37 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/10 12:26:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool		test_getCharOutput(const std::string& out, const std::string& expected, const std::string& testInfo)
{
	if (out == expected)
		return true;
	std::cerr << "[ERROR]: getCharOutput(" << "\"" << testInfo <<  "\")" << ": [out,  " << out <<  "] [expect, " << expected << "]" << std::endl;
	return (false);
}

bool		test_multiple_getCharOutput()
{
	int	counter = 0;
	int	tests = 8;
	
	std::cout << "> test_getCharOutput" << std::endl;
	counter += test_getCharOutput(getCharOutput(""), "Non displayable", "");
	counter += test_getCharOutput(getCharOutput("0"), "Non displayable", "0");
	counter += test_getCharOutput(getCharOutput("\t"), "Non displayable", "\\t");
	counter += test_getCharOutput(getCharOutput("a"), "a", "a");
	counter += test_getCharOutput(getCharOutput("aa"), "impossible", "aa");
	counter += test_getCharOutput(getCharOutput("a.0"), "impossible", "aa");
	counter += test_getCharOutput(getCharOutput("97.4"), "a", "97.4");
	counter += test_getCharOutput(getCharOutput("97.4f"), "a", "97.4f");
	if (counter == tests)
		std::cout << "[YOU PASS ALL THE TESTS]" << std::endl;
	else
		std::cout << "[YOU PASS " << counter << " / " << tests << " TESTS]" << std::endl;
	return (counter == tests);
}

std::string	getCharOutput(const std::string& s)
{	
	double floatValue = atof(s.c_str());

	if (floatValue > 0)
	{
		return 0;
	}
	if (std::isalpha(s[0]) && s.length() > 1)
		return "impossible";
	return "Hi";
}