/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:47:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 16:33:49 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name="Leehuek");
		~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
	private:
		Weapon*	_weapon;
		std::string	_name;
};
