/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:21:26 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:30:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type): type(Type)
{
	std::cout << "WrongAnimal type constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& obj)
{
	std::cout << "WrongAnimal copy constructor!" << std::endl;
	*this = obj;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& obj)
{
	std::cout << "WrongAnimal equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor!" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal making sound!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
