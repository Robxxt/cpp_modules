/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 14:12:48 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testOneGradeCase(int s, int e)
{
	std::cout << "sign: " << s << " exec: " << e << "-> ";
	try
	{
		Form a("one case", s, e);

		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}

void	testConstructors()
{
	std::cout << "\n[testConstructors]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	Form a;
	Form b("robert", 12, 15);
	Form c(b);
	Form d = c;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	std::cout << "-------------------------------------" << std::endl;
}

void	testMultipleGradeCases()
{
	std::cout << "\n[testMultipleGradeCases]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	testOneGradeCase(10, 15);
	testOneGradeCase(1, 15);
	testOneGradeCase(150, 15);
	testOneGradeCase(15, 10);
	testOneGradeCase(15, 1);
	testOneGradeCase(15, 0);
	testOneGradeCase(1, 151);
	testOneGradeCase(4, -1);
	testOneGradeCase(150, -15);
	std::cout << "-------------------------------------" << std::endl;
}

void	testSignOne(int grade, int signGrade)
{

	std::cout << "bureaucrat grade: " << grade << ", form sign grade " << signGrade << " -> ";
	Bureaucrat	b("Test", grade);
	Form	 	f("Form Test", signGrade, 10);

	try
	{
		f.beSigned(b);
		std::string	s = (f.getIsSigned() == false) ? "Not Signed" : "Signed";
		std::cout << s << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	testMultipleSignCases()
{
	std::cout << "\n[testMultipleSignCases]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	testSignOne(10, 15);
	testSignOne(10, 10);
	testSignOne(15, 10);
	std::cout << "-------------------------------------" << std::endl;
}
int	main()
{
	testConstructors();
	testMultipleGradeCases();
	testMultipleSignCases();
	
	std::cout << std::endl;
	return (0);
}