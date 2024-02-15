/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:31:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/09 14:26:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default.txt") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s), _target(s._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	if (this != &s)
	{
		_target = s._target;
	}
	return (*this);
}

bool	 ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (Form::tryToExec(executor) == false)
		return false;
	std::ofstream outfile(_target.c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Couldn't open the file " << _target << " to write on it";
		return false;
	}

	outfile << "      ^    * " << std::endl;
    outfile << "     ^^^  *  * " << std::endl;
    outfile << "    ^^^^^  * * " << std::endl;
    outfile << "   ^^^^^^^ *  " << std::endl;
    outfile << "  ^^^^^^^^^  " << std::endl;
    outfile << " ^^^^^^^^^^^ " << std::endl;
    outfile << "^^^^^^^^^^^^^" << std::endl;
    outfile << "     ||| rdragan" << std::endl;

	outfile.close();
	return true;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}