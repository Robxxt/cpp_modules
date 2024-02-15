/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:27:07 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 16:47:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon(void) {}

std::string&	Weapon::getType(void)
{
	return _type;
}

void			Weapon::setType(std::string type)
{
	_type = type;
}