/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:25:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/10 07:40:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Eustaquio"), _grade(1)
{
	std::cout << "creating Bureaucrat with default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1)
{
	std::cout << "creating Bureaucrat with name and default grade" << std::endl;

}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "creating Bureaucrat" << std::endl;

}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "creating Bureaucrat with default deconstructor" << std::endl;
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& bureaucrat)
{
	COUT << bureaucrat.getName() << ", " << "bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return (COUT);
}