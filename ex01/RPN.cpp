/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:13:02 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 02:39:49 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& in) : _result(0)
{
	std::stringstream	ss(in);
	std::string			item;
	int					items[2];
	int					out = 0;

	while (std::getline(ss, item, ' '))
	{
		if (!valid_item(item)) throw std::invalid_argument("Invalid item");
		else if (std::isdigit(item[0])) _stack.push(std::atoi(item.c_str()));
		else
		{
			items[1] = _stack.top();
			_stack.pop();
			items[0] = _stack.top();
			_stack.pop();
			out = operation(item[0], items);
			_stack.push(out);
		}
	}
	if (_stack.size() != 1) throw std::invalid_argument("There's no logic in your input!");
}

RPN::~RPN() {}

void	RPN::displayResult(void) const
{
	std::cout << _stack.top() << std::endl;
}