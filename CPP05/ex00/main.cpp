/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:47:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/10 07:42:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	default_bureaucrat;
	Bureaucrat	default_grade("Lorena");
	Bureaucrat	stephanie("Stephanie", 2);

	std::cout << default_bureaucrat;
	std::cout << default_grade;
	std::cout << stephanie;
	return (0);
}