/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:18:34 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/19 03:21:43 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat default constructor!" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(std::string Type): Animal(Type)
{
	std::cout << "Cat type constructor!" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const& obj): Animal(obj)
{
	std::cout << "Cat copy constructor!" << std::endl;
	*this = obj;
	this->_brain = new Brain();
}

Cat&	Cat::operator=(Cat const& obj)
{
	std::cout << "Cat equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor!" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau!" << std::endl;
}

const Brain*	Cat::getBrain(void) const
{
	return this->_brain;
}
