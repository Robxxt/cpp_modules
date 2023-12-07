/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 11:51:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testGrade(int grade)
{
	std::cout << "grade: " << grade << " -> ";
	try
	{
		Bureaucrat b("Robert", grade);
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testMultipleGradeCases()
{
	std::cout << "\n[testMultipleGradeCases]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	testGrade(150);
	testGrade(120);
	testGrade(10);
	testGrade(1);
	testGrade(0); //This throws gradeTooHigh
	testGrade(-1); //This throws gradeTooHigh
	std::cout << "-------------------------------------" << std::endl;
}

void	testGradeIncrement(int grade)
{
	std::cout << "grade: " << grade << " -> ";
	try
	{
		Bureaucrat b("Robert", grade);
		std::cout << "incrementing ...-> ";
		b.incrementGrade();
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testGradeDecrement(int grade)
{
	std::cout << "grade: " << grade << " -> ";
	try
	{
		Bureaucrat b("Robert", grade);
		std::cout << "decrementing ...-> ";
		b.decrementGrade();
		std::cout << b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testMultipleGradeIncrement()
{
	std::cout << "\n[testMultipleGradeIncrement]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	testGradeIncrement(1); //This throws gradeTooHigh
	testGradeIncrement(2);
	testGradeIncrement(150);
	std::cout << "-------------------------------------" << std::endl;
}

void	testMultipleGradeDecrement()
{
	std::cout << "\n[testMultipleGradeDecrement]" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	testGradeDecrement(1);
	testGradeDecrement(2);
	testGradeDecrement(150); //This throws gradeTooLow
	std::cout << "-------------------------------------" << std::endl;
}

void	testConstructors()
{
	Bureaucrat b("robert", 15);
	Bureaucrat c(b);
	Bureaucrat d = c;

	std::cout << b;
	std::cout << c;
	std::cout << d;
}

int	main()
{
	testConstructors();
	testMultipleGradeCases();
	testMultipleGradeIncrement();
	testMultipleGradeDecrement();
	
	std::cout << std::endl;
	return (0);
}