/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:18:23 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 15:11:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	printZombies(int N, Zombie *zombies)
{
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
}

int	main(void)
{
	Zombie	*zombies = zombieHorde(10, "Leehuek");
	printZombies(10, zombies);
	delete [] zombies;
	return (0);
}
