/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:20:33 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 11:55:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base * generate(void)
{
	Base *ptr = NULL;

	int randomNumber = rand() % 3;
	if (randomNumber == 0)
		ptr = new A;
	else if (randomNumber == 1)
		ptr = new B;
	else
		ptr = new C;
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	(void)p;
}
