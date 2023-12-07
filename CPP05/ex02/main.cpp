/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 17:37:30 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

void	testOneExecute()
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

int	main()
{
	// testConstructors();
	testOneExecute();
	return (0);
}