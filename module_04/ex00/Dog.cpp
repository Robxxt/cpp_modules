/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:07:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:10:05 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog default constructor!" << std::endl;
}

Dog::Dog(std::string Type): Animal(Type)
{
	std::cout << "Dog type constructor!" << std::endl;
}

Dog::Dog(Dog const& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor!" << std::endl;
	*this = obj;
}

Dog&	Dog::operator=(Dog const& obj)
{
	std::cout << "Dog equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor!" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "HamHam!" << std::endl;
}
