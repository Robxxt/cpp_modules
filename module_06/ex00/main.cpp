/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:50:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 16:16:02 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You must provide one argument to the program!" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (char *excp)
	{
		std::cout << excp;
	}
	return (0);
}
