/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:14:20 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/19 20:40:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	// Animal	a;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal	*Animals[10];

	delete j;//should not create a leak
	delete i;

	for (int z = 0; z < 5; z++)
	{
		Animals[z] = new Dog();
		std::cout << "DOG [" << z << "]: " << (((Dog *)Animals[z])->getBrain()->getIdea(z)) << std::endl;
		Animals[z]->makeSound();
	}
	for (int k = 5; k < 10; k++)
	{
		Animals[k] = new Cat();
		std::cout << "CAT [" << k << "]: " << (((Cat *)Animals[k])->getBrain()->getIdea(k)) << std::endl;
		Animals[k]->makeSound();
	}

	for (int y = 0; y < 10; y++)
	{
		delete Animals[y];
	}
	
	Dog basic;
	{
		Dog tmp = basic;
	}
	return (0);
}
