/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:26:01 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 18:09:23 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data *h = new Data;
	uintptr_t newH = Serializer::serialize(h);
	Data*	againH = Serializer::deserialize(newH);
	std::cout << "h = " << h << std::endl;
	std::cout << "Data* newH = serialize(h) = " << newH << std::endl;
	std::cout << "uintptr_t againH = deserialize(h) = " << againH << std::endl;
	delete h;
}