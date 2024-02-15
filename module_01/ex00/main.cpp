/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:18:23 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 15:04:52 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z("Luis");
	Zombie	*y = newZombie("Jose");
	z.announce();
	y->announce();
	delete y;
	randomChump("Randy");
	return (0);
}
