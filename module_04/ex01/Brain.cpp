/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:44 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/19 20:38:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			_ideas[i] = "Idea even";
		else
			_ideas[i] = "Idea odd";
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(Brain const& obj)
{
	std::cout << "Brain copy constructor!" << std::endl;
	*this = obj;
}

Brain&	Brain::operator=(Brain const& obj)
{
	std::cout << "Brain equal opeartor overload called!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = obj._ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	return _ideas[index];
}
