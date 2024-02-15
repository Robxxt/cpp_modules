/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:53:58 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 20:24:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <string>
# include <iomanip>
# include <cctype>

void	printSpecial(const std::string& s);
void	printFromChar(const std::string& s);
void	printFromFloat(const std::string& s);
void	printFromDouble(const std::string& s);
void	printFromInt(const std::string& s);

bool	isSpecial(const std::string& s);
bool	inputIsFloatFormat(const std::string& s);
bool	inputIsDoubleFormat(const std::string& s);
bool	inputIsIntFormat(const std::string& s);

#endif