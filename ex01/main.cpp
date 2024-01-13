/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:10:42 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/13 01:17:26 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		(argc == 1) ? std::cerr << "[ERROR]: You must provide one argument!" << std::endl : std::cerr << "[ERROR]: Too many arguments!" << std::endl;
		return (1);
	}
	RPN	rpn(argv[1]);
}