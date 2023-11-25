/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:20:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/25 18:43:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
class Form
{
private:
	std::string	_name;
	bool		_isSigned;
	const int	_gradeToSign;
	const int	_gradeToExecute;

public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form& obj);
	Form& operator=(Form&obj);
	~Form();
	std::string	getName();
	int		getGradeToSign();
	int		getGradeToExecute();
	bool 	getIsSigned();
	void 	beSigned(Bureaucrat& bureaucrat);
	class GradeTooHighException: public std::exception
	{
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& COUT, Form& f);

#endif