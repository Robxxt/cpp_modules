/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:14:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 20:58:48 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << "Animal default constructor!" << std::endl;
}

Animal::Animal(std::string Type): type(Type)
{
	std::cout << "Animal type constructor!" << std::endl;
}

Animal::Animal(Animal const& obj)
{
	std::cout << "Animal copy constructor!" << std::endl;
	*this = obj;
}

Animal&	Animal::operator=(Animal const& obj)
{
	std::cout << "Animal equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor!" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal making sound!" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
