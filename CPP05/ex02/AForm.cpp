/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 12:59:24 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHigh");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("GradeLowHigh");
}

AForm::AForm(void) : _name("default form"), _signed(false), _gradeToSign(10), _gradeToExec(5) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();\
		     
}

std::string	AForm::getName(void)
{
	return (this->_name);
}

bool		AForm::getSigned(void)
{
	return (this->_signed);
}

int			AForm::getGradeToSign(void)
{
	return (this->_gradeToSign);
}

int			AForm::getGradeToExec(void)
{
	return (this->_gradeToExec);
}

void		AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign && b.getGrade() > 0)
		this->_signed = true;
	else if (b.getGrade() <= 0)
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

AForm::~AForm() {}

std::ostream&	operator<<(std::ostream& COUT, AForm& form)
{
	COUT << form.getName() << "=> " << "signed: " << form.getSigned() << " " \
	     << "gradeToSign: " << form.getGradeToSign() << " " << "gradeToExec: " \
         << form.getGradeToExec() << std::endl;
	return (COUT);
}