/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:35:07 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 19:37:34 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default.txt") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : AForm(s), _target(s._target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return (*this);
}

bool	 PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (AForm::tryToExec(executor) == false)
		return false;
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;

	return true;
}

PresidentialPardonForm::~PresidentialPardonForm() {}