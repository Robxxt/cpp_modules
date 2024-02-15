/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:06:03 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/09 14:26:28 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default.txt") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : Form(s), _target(s._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return (*this);
}

bool	 RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (Form::tryToExec(executor) == false)
		return false;
	std::cout << "TRRRRRTRRRRTRRR ...  ";

    int randomValue = std::rand() % 2;
	if (randomValue == 0)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
	{
		std::cout << _target << " couldn't been robotomized" << std::endl;
		return false;
	}
	return true;
}

RobotomyRequestForm::~RobotomyRequestForm() {}