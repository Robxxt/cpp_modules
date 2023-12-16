/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:09:59 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/16 11:55:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	testIdentifyWithPointer()
{
	std::cout << "Test void identify(Base* p)" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Base *a[20];
	for (int i = 0; i < 20; i++)
		a[i] = generate();
	for (int i = 0; i < 20; i++)
		identify(a[i]);
	for (int i = 0; i < 20; i++)
		delete a[i];
	std::cout << "----------------------------" << std::endl;
}

int	main()
{
	testIdentifyWithPointer();
	return (0);
}