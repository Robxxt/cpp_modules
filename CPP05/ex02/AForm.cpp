/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:05:49 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "FormGradeTooLowException";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "FormGradeTooHighException";
}

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(SIGN_GRADE), _gradeToExec(EXEC_GRADE) {}

AForm::AForm(const std::string& name, int gs, int ge) : _name(name), _isSigned(false), _gradeToSign(gs), _gradeToExec(ge)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& f) : _name(f._name), _isSigned(f._isSigned), _gradeToSign(f._gradeToSign), _gradeToExec(f._gradeToExec) {}

AForm&	AForm::operator=(const AForm& f)
{
	if (this != &f)
	{
		_name = f._name;
		_isSigned = f._isSigned;
	}
	return (*this);
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool				AForm::getIsSigned() const
{
	return _isSigned;
}

int					AForm::getGradeToSign() const
{
	return _gradeToSign;
}


int					AForm::getGradeToExec() const
{
	return _gradeToExec;
}

void				AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

AForm::~AForm() {}

std::ostream&	operator<<(std::ostream& OUT, AForm& f)
{
	std::string	isSigned = (f.getIsSigned() == false) ? "not singed" : "signed";
	
	OUT << f.getName() << ", " << isSigned << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << std::endl;
	return (OUT);
}