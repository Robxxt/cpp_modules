/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:00:02 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/16 17:27:33 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :	_name("Agustin"), _hitPointsHealth(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor is called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name), _hitPointsHealth(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor is called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& obj)
{
	std::cout << "ClapTrac copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor is called!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &obj)
{
	this->_attackDamage = obj._attackDamage;
	this->_hitPointsHealth = obj._hitPointsHealth;
	this->_energyPoints = obj._energyPoints;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " HP damage" << std::endl;
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPointsHealth > 0)
	{
		_hitPointsHealth -= amount;
		if (_hitPointsHealth < 0)
		{
			_hitPointsHealth = 0;
		}
		std::cout << "ClapTrap " << _name << " was attacked " << "and lost " << amount << " HP" << std::endl;
	}
	else
	{
		std::cout << "In order to be killed first you would need to be alive. And you are NOT!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		_hitPointsHealth += amount;

		std::cout << "ClapTrap " << _name << " restored " << amount << " HP" << std::endl;
	}
}

int		ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}

int		ClapTrap::getHitPointsHealth(void)
{
	return (_hitPointsHealth);
}

int		ClapTrap::getEnergyPoints(void)
{
	return (_energyPoints);
}

void		ClapTrap::setAttackDamage(int newAttackDamage)
{
	std::cout << "Modified attack of " << _name << " to " << newAttackDamage << std::endl;
	this->_attackDamage = newAttackDamage;
}

void		ClapTrap::setHitPointsHealth(int newHitPointsHealth)
{
	std::cout << "Modified HP of " << _name << " to " << newHitPointsHealth << std::endl;
	this->_hitPointsHealth = newHitPointsHealth;
}

void		ClapTrap::setEnergyPoints(int newEnergyPoints)
{
	std::cout << "Modified EP of " << _name << " to " << newEnergyPoints << std::endl;
	this->_energyPoints = newEnergyPoints;
}

void	ClapTrap::printStatistics(void)
{
	for (std::string::size_type i = 0; i < (_name.length() + 6); i++)
		std::cout << '-';
	std::cout << std::endl;	
	std::cout << "User: " << _name << std::endl;
	for (std::string::size_type i = 0; i < (_name.length() + 6); i++)
		std::cout << '-';
	std::cout << std::endl;	
	std::cout << "HP\t\tEnergy\t\tAttak" << std::endl;
	std::cout << _hitPointsHealth << "\t\t";
	std::cout << _energyPoints << "\t\t";
	std::cout << _attackDamage << std::endl;
}
