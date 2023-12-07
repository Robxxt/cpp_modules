/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:21:40 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 13:54:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

# ifndef SIGN_GRADE
#  define SIGN_GRADE 120
# endif

# ifndef EXEC_GRADE
#  define EXEC_GRADE 120
# endif

class	Form
{
private:
	std::string _name;
	bool		_isSigned;
	int			_gradeToSign;
	int			_gradeToExec;
public:
	Form();
	Form(const std::string& name, int gs, int ge);
	Form(const Form& f);
	Form&				operator=(const Form& f);
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	void				beSigned(const Bureaucrat& b);
	~Form();

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& OUT, Form& f);

#endif