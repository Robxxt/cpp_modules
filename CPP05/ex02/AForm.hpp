/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:21:40 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:02:30 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class	AForm
{
private:
	std::string _name;
	bool		_isSigned;
	int			_gradeToSign;
	int			_gradeToExec;
public:
	AForm();
	AForm(const std::string& name, int gs, int ge);
	AForm(const AForm& f);
	AForm&				operator=(const AForm& f);
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	void				beSigned(const Bureaucrat& b);
	~AForm();

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

std::ostream&	operator<<(std::ostream& OUT, AForm& f);

#endif