/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:53:36 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 14:06:04 by rdragan          ###   ########.fr       */
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