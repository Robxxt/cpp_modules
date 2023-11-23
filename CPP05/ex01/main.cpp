/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:47:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 16:55:25 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	constructFormWithExceptions()
{
	try
	{
		Form		f2("f2", 151, 10);
		std::cout << f2;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		f2("f2", 10, -1);
		std::cout << f2;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
[NOTE]: IN THIS EXCERSISE HIGH IS 1 AND LOW IS 150
*/
int	main(void)
{
	Form		f1("f1", 10, 10);
	constructFormWithExceptions();
	try
	{
		// Changing it to be bigger than 10 will throw an exception
		// Changing it to be lower than 1 will throw an exception
		Bureaucrat b1("b1", 5);
		// remove and won't be signed
		f1.beSigned(b1);
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << f1;
}
