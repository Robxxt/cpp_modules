/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:31:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:46:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 45, 137), _target("default.txt") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 45, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : AForm(s), _target(s._target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "HI" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}