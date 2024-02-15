/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/07 16:55:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	trimSpaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << " ";
	}
}

/*
If a string is smaller than 10 char prints it.
Otherwise prints the first 10 char and a "dot(.)".
*/
void	printFormattedText(std::string str)
{
	int	slen = str.length();
	if (slen > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		trimSpaces((10 - slen) / 2);
		if ((10 - slen) % 2 == 0)
		{
			std::cout << str;
			trimSpaces((10 - slen) / 2);
		}
		else
		{
			std::cout << str;
			trimSpaces((10 - slen) / 2 + 1);
		}
	}
}

bool	isEmpyt(std::string str)
{
	if (str.empty())
		return (true);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!(std::isspace(str[i])))
		{
			return (false);
		}
	}
	return (true);
}