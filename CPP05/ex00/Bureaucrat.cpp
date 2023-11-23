/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:39:28 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 14:45:51 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& obj)
{
	this->_grade = obj.getGrade();
	this->_name = obj.getName();
	return (*this);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception Grade Too Low!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception Grade Too High!");
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}
int			Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	this->_grade--;
}

void		Bureaucrat::decrementGrade(void)
{
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& b)
{
	COUT << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (COUT);
}