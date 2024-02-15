/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/09 14:44:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	testOneCase(const std::string& form)
{
	Bureaucrat	b("Robert", 1);
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm(form, "Bender");

	if (rrf)
	{
		rrf->beSigned(b);
		b.executeForm(*rrf);
	}
	delete rrf;
}

void	testMultipleCases()
{
	testOneCase("ShrubberyCreationForm");
	testOneCase("RobotomyRequestForm");
	testOneCase("PresidentialPardonForm");
	testOneCase("NonExistingForm");
}

int	main()
{
	testMultipleCases();
	return (0);
}