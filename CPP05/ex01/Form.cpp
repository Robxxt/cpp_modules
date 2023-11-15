/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 10:59:41 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHigh");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeLowHigh");
}

Form::Form(void) : _name("default form"), _signed(false), _gradeToSign(10), _gradeToExec(5) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();\
		     
}

std::string	Form::getName(void)
{
	return (this->_name);
}

bool		Form::getSigned(void)
{
	return (this->_signed);
}

int			Form::getGradeToSign(void)
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExec(void)
{
	return (this->_gradeToExec);
}

void		Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign && b.getGrade() > 0)
		this->_signed = true;
	else if (b.getGrade() <= 0)
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

Form::~Form() {}

std::ostream&	operator<<(std::ostream& COUT, Form& form)
{
	COUT << form.getName() << "=> " << "signed: " << form.getSigned() << " " \
	     << "gradeToSign: " << form.getGradeToSign() << " " << "gradeToExec: " \
         << form.getGradeToExec() << std::endl;
	return (COUT);
}