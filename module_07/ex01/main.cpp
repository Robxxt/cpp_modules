/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:03:46 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/26 15:48:47 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	sayHi(T i)
{
	std::cout << "sayHi to " << i << std::endl;
}

void	tests()
{
	std::cout << "> called iter with strings" << std::endl;
	std::string name[] = {"Robert", "Veronika", "Marta", "Luis"};
	iter(name, 4, &sayHi);

	std::cout << "> called iter with ints" << std::endl;
	int grades[] = {10, 9, 8, 7};
	iter(grades, 4, &sayHi);
}

int	main(void)
{
	tests();
	return (0);
}
