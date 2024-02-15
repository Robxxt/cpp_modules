/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:57:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/09 14:39:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& i)
{
	(void)i;
}

Intern& Intern::operator=(const Intern& i)
{
	(void)i;
	return *this;
}

Form*	Intern::makeForm(const std::string& form, const std::string& target)
{
	Form	*returnedForm = NULL;
	std::string validForms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int	i = 0;
	
	while (i < 3 && validForms[i] != form) i++;
	switch(i)
	{
		case 0:
			returnedForm = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form << std::endl;
			break ;
		case 1:
			returnedForm = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form << std::endl;
			break ;
		case 2:
			returnedForm = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form << std::endl;
			break ;
		default:
			std::cerr << "[ERROR]: The formulary type you want to create doesn't exists exists!" << target << std::endl;
			break ;

	}
	return returnedForm;
}


Intern::~Intern() {}