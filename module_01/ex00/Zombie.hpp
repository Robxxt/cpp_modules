/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:33:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/10 09:35:50 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name="Default Zombie");
		~Zombie(void);
		void		announce(void);
	private:
		std::string _name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif