/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:10:59 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 01:52:08 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>

class RPN
{
private:
	// std::stack<int> _stack;
	int	_result;
	RPN();
	RPN(const RPN& in);
	RPN& operator=(const RPN& in);
public:
	RPN(const std::string& in);
	~RPN();
};

bool	valid_item(const std::string& item);

#endif