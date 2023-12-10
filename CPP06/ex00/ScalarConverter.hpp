/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:33 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/10 10:49:56 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& s);
	ScalarConverter& operator=(const ScalarConverter& s);
	static void	convert(const std::string& s);
	~ScalarConverter();
};

#endif