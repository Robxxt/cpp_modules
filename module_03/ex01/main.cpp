/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:38:10 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/16 23:17:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	userA;
	ScavTrap	enemy("Enemy");
	ScavTrap	enemy1(enemy);
	ScavTrap	enemy2 = enemy1;

	userA.printStatistics();
	userA.attack("WTF");
	userA.takeDamage(3);
	userA.takeDamage(1);
	userA.takeDamage(4);
	userA.takeDamage(10);
	userA.takeDamage(10);
	enemy1.printStatistics();
	enemy1.takeDamage(10);
	userA.takeDamage(10);
	userA.takeDamage(10);
	userA.beRepaired(10);
	userA.printStatistics();
	userA.attack("Whaaat...");
	userA.printStatistics();
	userA.setAttackDamage(1000);
	userA.printStatistics();
	userA.guardGate();
}
