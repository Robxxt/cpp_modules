/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 19:22:14 by rdragan          ###   ########.fr       */
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

void	testShrubberyCreationForm()
{
	Bureaucrat a("robert", 43);
	ShrubberyCreationForm t("Test");
	
	try
	{
		t.beSigned(a); // Needs to be signed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	t.execute(a);
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


int	main()
{
	// testConstructors();
	// testShrubberyCreationForm();
	testMultipleRobotmyRequestForm();
	return (0);
}