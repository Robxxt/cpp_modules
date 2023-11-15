/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:25:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 10:47:41 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

char const*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException";
}

char const*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException";
}

Bureaucrat::Bureaucrat(void): _name("Eustaquio"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooHighException();
	_grade++;
}

void		Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& bureaucrat)
{
	COUT << bureaucrat.getName() << ", " << "bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (COUT);
}