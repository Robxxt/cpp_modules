/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:13:02 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 01:52:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& in) : _result(0)
{
	std::stringstream	ss(in);
	std::string			item;

	while (std::getline(ss, item, ' '))
	{
		if (!valid_item(item)) throw std::invalid_argument("Invalid item");
	}
}

RPN::~RPN() {}