/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 16:50:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class	Form;
class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(Bureaucrat &obj);
	~Bureaucrat();
	std::string	getName(void);
	int			getGrade(void);
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form& f);
	class GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& b);

#endif