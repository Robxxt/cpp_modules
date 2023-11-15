/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:55:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/15 12:57:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	AForm
{
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	~AForm();
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

std::ostream&	operator<<(std::ostream& COUT, AForm&	form);

#endif