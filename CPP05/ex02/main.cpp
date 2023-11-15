/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:47:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 12:58:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat	lorena("lorena", 9);
	Bureaucrat	veronika("veronika", 10);

	try
	{
		AForm		f1("f1", 8, 15);
		lorena.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm		f2("f2", 20, 15);
		lorena.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm		f3("f3", 3, 15);
		veronika.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm		f4("f4", 20, 15);
		veronika.signForm(f4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}