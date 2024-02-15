/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:23:21 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 16:47:16 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string&	getType(void);
		void			setType(std::string type);
	private:
		std::string	_type;
};

#endif