/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:53:58 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 19:36:14 by rdragan          ###   ########.fr       */
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

// void	display_one_char(const std::string& s);
bool	isSpecial(const std::string& s);
void	printSpecial(const std::string& s);
void	printFromChar(const std::string& s);

// void	printNormal(const std::string& s);
bool	inputIsFloatFormat(const std::string& s);

#endif