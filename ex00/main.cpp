/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:25:09 by rdragan           #+#    #+#             */
/*   Updated: 2024/01/03 02:38:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

bool	isValidFile(const std::string& filename)
{
	std::ifstream file(filename);
	return (file.good());
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !isValidFile(argv[1]))
	{
		std::cerr << "Error: could not open file" << std::endl;
	}
	else
	{
		std::cout << "You can read from the file" << std::endl;
	}
	return (0);
}