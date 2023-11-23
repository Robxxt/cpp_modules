/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:47:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 14:47:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat r("Robert", 1);
	Bureaucrat l("Luismi", 150);
	Bureaucrat l2(l);
	Bureaucrat r2(r);
	
	try
	{
		Bureaucrat m("Marta", 0);
		std::cout << m;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	r2.decrementGrade();
	l2.incrementGrade();
	std::cout << r;
	std::cout << r2;
	std::cout << l;
	std::cout << l2;
}