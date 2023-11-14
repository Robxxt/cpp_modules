/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:47:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/14 09:26:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	default_bureaucrat;
	Bureaucrat	default_grade("Lorena");
	Bureaucrat	stephanie("Stephanie", 2);
	Bureaucrat	matilde("Matilde", 149);
	try
	{
		Bureaucrat	luis("Luis", -2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	marta("Marta", 250);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << default_bureaucrat;
	std::cout << default_grade;
	std::cout << stephanie;
	std::cout << matilde;

	try
	{
		default_bureaucrat.incrementGrade();
		std::cout << default_bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "incrementGrade: " << e.what() << std::endl;
	}
	try
	{
		stephanie.incrementGrade();
		std::cout << stephanie;
	}
	catch (std::exception &e)
	{
		std::cout << "incrementGrade: " << e.what() << std::endl;
	}
	try
	{
		matilde.decrementGrade();
		std::cout << matilde;
	}
	catch (std::exception &e)
	{
		std::cout << "decrementGrade: " << e.what() << std::endl;
	}
	try
	{
		matilde.decrementGrade();
		std::cout << matilde;
	}
	catch (std::exception &e)
	{
		std::cout << "decrementGrade: " << e.what() << std::endl;
	}
	return (0);
}