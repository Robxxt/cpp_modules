/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:23 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:00:26 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(10) {}

Bureaucrat::Bureaucrat(Bureaucrat& b): _name(b._name), _grade(b._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		_grade = b._grade;
		_name = b._name;
	}
	return (*this);
}

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

void	Bureaucrat::signForm(const Form& f)
{
	std::string reason = "user grade is too low to sign this form";
	if (f.getIsSigned() == true)
	{
		std::cout << _name << " signed " << f.getName();
	}
	else
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << reason;
	}
	std::cout << std::endl;
}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& OUT, Bureaucrat& b)
{
	OUT << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (OUT);
}