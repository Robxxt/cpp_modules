/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:45:08 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/07 16:04:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;
class Bureaucrat
{
private:
	std::string _name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat& b);
	Bureaucrat&	operator=(const Bureaucrat& b);
	const	std::string&	getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(const AForm& f);
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
	~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& OUT, Bureaucrat& b);


#endif