/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:48:42 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/10 10:45:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	_options[0] = "debug";
	_options[1] = "info";
	_options[2] = "warning";
	_options[3] = "error";
}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void(Harl::*functions)();
	Harl		tmp;

	functions	myFunc[4];
	myFunc[0] = &Harl::debug;
	myFunc[1] = &Harl::info;
	myFunc[2] = &Harl::warning;
	myFunc[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == _options[i])
			(tmp.*myFunc[i])();
	}
}
