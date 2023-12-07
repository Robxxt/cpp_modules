/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:58:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:44:21 by rdragan          ###   ########.fr       */
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

int	main()
{
	testConstructors();
	std::cout << std::endl;
	return (0);
}