/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:48:45 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/10 07:39:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	// Bureaucrat(const Bureaucrat& obj);
	// Bureaucrat&	operator=(const Bureaucrat& obj);
	~Bureaucrat(void);
	std::string	getName(void);
	int			getGrade(void);
	// void		incrementGrade(void);
	// void		decrementGrade(void);

private:
	std::string	_name;
	// grade must be between [150-1] 150:low 1:high
	int	_grade;
};

std::ostream&	operator<<(std::ostream& COUT, Bureaucrat&	bureaucrat);

#endif