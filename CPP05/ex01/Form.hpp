/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 10:42:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	~Form();
	std::string	getName(void);
	bool		getSigned(void);
	int			getGradeToSign(void);
	int			getGradeToExec(void);
	void		beSigned(Bureaucrat& b);
	
	class	GradeTooLowException: public std::exception
	{
		const char*	what(void) const throw();
	};
	class	GradeTooHighException: public std::exception
	{
		const char*	what(void) const throw();
	};
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream&	operator<<(std::ostream& COUT, Form&	form);

#endif