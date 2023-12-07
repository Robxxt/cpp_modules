/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 14:10:22 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char*	Form::GradeTooLowException::what() const throw()
{
	return "FormGradeTooLowException";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "FormGradeTooHighException";
}

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(SIGN_GRADE), _gradeToExec(EXEC_GRADE) {}

Form::Form(const std::string& name, int gs, int ge) : _name(name), _isSigned(false), _gradeToSign(gs), _gradeToExec(ge)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& f) : _name(f._name), _isSigned(f._isSigned), _gradeToSign(f._gradeToSign), _gradeToExec(f._gradeToExec) {}

Form&	Form::operator=(const Form& f)
{
	if (this != &f)
	{
		_name = f._name;
		_isSigned = f._isSigned;
	}
	return (*this);
}

const std::string&	Form::getName() const
{
	return _name;
}

bool				Form::getIsSigned() const
{
	return _isSigned;
}

int					Form::getGradeToSign() const
{
	return _gradeToSign;
}


int					Form::getGradeToExec() const
{
	return _gradeToExec;
}

void				Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

Form::~Form() {}

std::ostream&	operator<<(std::ostream& OUT, Form& f)
{
	std::string	isSigned = (f.getIsSigned() == false) ? "not singed" : "signed";
	
	OUT << f.getName() << ", " << isSigned << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << std::endl;
	return (OUT);
}