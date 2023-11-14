/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:47 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/14 09:39:20 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
public:
	Form();
	Form(std::string name);
	~Form();
private:
	std::string	_name;
	bool		_signed;
	const int	_grade_to_sign;
	const int	_grade_to_exec;
};

#endif