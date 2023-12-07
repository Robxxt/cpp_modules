/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:23 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 11:43:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(10) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooHighException();
	_grade = grade;
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}
void	Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& OUT, Bureaucrat& b)
{
	OUT << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (OUT);
}