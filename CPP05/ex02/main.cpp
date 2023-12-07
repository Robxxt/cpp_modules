/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 19:32:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	testConstructors()
{
	std::cout << "\n[testConstructors]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	ShrubberyCreationForm a;
	ShrubberyCreationForm b("robert");
	ShrubberyCreationForm c(b);
	ShrubberyCreationForm d = c;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	std::cout << "-------------------------------------" << std::endl;
}

bool	testRobotomyRequestForm()
{
	Bureaucrat a("robert", 43);
	RobotomyRequestForm t("Test");
	
	try
	{
		t.beSigned(a); // Needs to be signed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (t.execute(a));
}

void	testMultipleRobotmyRequestForm()
{
	int	totalCases = 1000;
	int	positive = 0;
	for (int i = 0; i < totalCases; i++)
	{
		if (testRobotomyRequestForm() == true)
			positive++;
	}
	std::cout << "Total positive : " << (positive * 100) / totalCases << " %" << std::endl;
}

void	testExecuteForm()
{
	Bureaucrat a("robert", 46);
	ShrubberyCreationForm t1("Test");
	RobotomyRequestForm t2("Test");

	t1.beSigned(a);
	t2.beSigned(a);
	a.executeForm(t1);
	a.executeForm(t2);
}

int	main()
{
	// testConstructors();
	// testExecuteForm();
	// testMultipleRobotmyRequestForm();
	return (0);
}