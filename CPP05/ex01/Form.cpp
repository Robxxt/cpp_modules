/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:20:24 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 16:50:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: Exception Grade Too High!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form: Exception Grade Too Low!");
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	:_name(name), _isSigned(false), 
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(Form& obj)
	: _name(obj._name), _isSigned(obj._isSigned),
	_gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

std::string	Form::getName()
{
	return (this->_name);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else if (bureaucrat.getGrade() < 1)
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

int	Form::getGradeToSign()
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute()
{
	return (this->_gradeToExecute);
}

bool	Form::getIsSigned()
{
	return (this->_isSigned);
}

std::ostream&	operator<<(std::ostream& COUT, Form& f)
{
	COUT << "FORM INFORMATION: " << std::endl;
	COUT << "name: " << f.getName();
	COUT << "\tgradeToSign: " << f.getGradeToSign();
	COUT << "\tgradeToSign: " << f.getGradeToSign();
	COUT << "\tisSigned: ";
	if (f.getIsSigned() == true)
		COUT << "true";
	else
		COUT << "false";
	COUT << std::endl;
	return (COUT);
}


Form::~Form() {}