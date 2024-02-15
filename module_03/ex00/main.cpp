/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:10 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/16 17:27:01 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	userA;
	ClapTrap	enemy("Enemy");
	ClapTrap	enemy1(enemy);

	userA.printStatistics();
	userA.attack("WTF");
	userA.takeDamage(3);
	userA.takeDamage(1);
	userA.takeDamage(4);
	userA.takeDamage(10);
	userA.takeDamage(10);
	userA.takeDamage(10);
	userA.takeDamage(10);
	userA.takeDamage(10);
	userA.beRepaired(10);
	userA.printStatistics();
	userA.setAttackDamage(100);
	userA.attack("Whaaat...");
	userA.setEnergyPoints(100);
	userA.setHitPointsHealth(100);
	userA.printStatistics();

}
