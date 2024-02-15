/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:07:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:33:16 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void): WrongAnimal("WrongDog")
{
	std::cout << "WrongDog default constructor!" << std::endl;
}

WrongDog::WrongDog(std::string Type): WrongAnimal(Type)
{
	std::cout << "WrongDog type constructor!" << std::endl;
}

WrongDog::WrongDog(WrongDog const& obj) : WrongAnimal(obj)
{
	std::cout << "WrongDog copy constructor!" << std::endl;
	*this = obj;
}

WrongDog&	WrongDog::operator=(WrongDog const& obj)
{
	std::cout << "WrongDog equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor!" << std::endl;
}

void	WrongDog::makeSound(void) const
{
	std::cout << "HamHam!" << std::endl;
}
