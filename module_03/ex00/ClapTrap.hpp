/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:00:05 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/16 17:23:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class	ClapTrap
{
private:
	std::string	_name;
	int			_hitPointsHealth;
	int			_energyPoints;
	int			_attackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& obj);
	ClapTrap&	operator=(ClapTrap const &obj);
	~ClapTrap(void);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		getAttackDamage(void);
	int		getHitPointsHealth(void);
	int		getEnergyPoints(void);
	void	setAttackDamage(int newAttackDamage);
	void	setHitPointsHealth(int newHitPointsHealth);
	void	setEnergyPoints(int newEnergyPoints);
	void	printStatistics(void);
};

#endif