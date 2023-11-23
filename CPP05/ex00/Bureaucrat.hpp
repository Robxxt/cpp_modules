/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/23 11:52:43 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat &obj);
	~Bureaucrat();
	std::string	getName(void);
	int			getGrade(void);
	void		incrementGrade(void);
	void		decrementGrade(void);
};

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat& b);

#endif