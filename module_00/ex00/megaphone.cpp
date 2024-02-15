/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:56:17 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/01 15:29:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (std::islower(str[i]))
		{
			str[i] -= 32;
		}
		std::cout << str[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			print_upper(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}