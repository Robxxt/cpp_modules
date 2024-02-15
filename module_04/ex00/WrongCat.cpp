/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:21:38 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:33:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor!" << std::endl;
}

WrongCat::WrongCat(std::string Type): WrongAnimal(Type)
{
	std::cout << "WrongCat type constructor!" << std::endl;
}

WrongCat::WrongCat(WrongCat const& obj): WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor!" << std::endl;
	*this = obj;
}

WrongCat&	WrongCat::operator=(WrongCat const& obj)
{
	std::cout << "WrongCat equal opeartor overload called!" << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor!" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miau!" << std::endl;
}
