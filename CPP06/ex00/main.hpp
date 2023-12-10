/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:55:34 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/10 11:40:04 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "ScalarConverter.hpp"

bool		test_getCharOutput(const std::string& s1, const std::string& s2, const std::string& testInfo);
bool		test_multiple_getCharOutput();

std::string	getCharOutput(const std::string& s);

#endif