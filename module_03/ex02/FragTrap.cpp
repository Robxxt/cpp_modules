/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:57:58 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/17 01:02:30 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_name = "Agustino";
	_hitPointsHealth = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor is called and is different!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPointsHealth = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor is called and is different!" << std::endl;
}

FragTrap::FragTrap(ClapTrap const& obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called and is different" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& obj)
{
	this->_attackDamage = obj._attackDamage;
	this->_hitPointsHealth = obj._hitPointsHealth;
	this->_energyPoints = obj._energyPoints;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor is called and is different!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " HP damage" << std::endl;
	}
	else if (_hitPointsHealth < 0)
	{
		std::cout << "You don't have live. You can't attack. You are not a ghost!" << std::endl;
	}
	else
	{
		std::cout << "You don't have enough energy points to attack" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " caled highFiveGuis" << std::endl;
}
