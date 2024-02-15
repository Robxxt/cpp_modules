/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:30:49 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/17 01:03:03 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_name = "Agustino";
	_hitPointsHealth = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor is called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPointsHealth = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor is called!" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap const& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& obj)
{
	this->_attackDamage = obj._attackDamage;
	this->_hitPointsHealth = obj._hitPointsHealth;
	this->_energyPoints = obj._energyPoints;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor is called!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " HP damage" << std::endl;
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is guarding the gate!" << std::endl;
}
