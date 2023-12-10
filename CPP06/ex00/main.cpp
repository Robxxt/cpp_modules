/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:50:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/10 11:16:00 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You must provide one argument to the program!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	test_multiple_getCharOutput();
	return (0);
}
