/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:07:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/19 03:38:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog default constructor!" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(std::string Type): Animal(Type)
{
	std::cout << "Dog type constructor!" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor!" << std::endl;
	*this = obj;
	this->_brain = new Brain();
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
	delete this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "HamHam!" << std::endl;
}

const Brain*	Dog::getBrain(void) const
{
	return this->_brain;
}

