/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:13:02 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 01:24:34 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& in) : _result(0)
{
	std::stringstream	ss(in);
	std::string			item;

	while (std::getline(ss, item, ' '))
	{
		std::cout << item << std::endl;
	}
}

RPN::~RPN() {}