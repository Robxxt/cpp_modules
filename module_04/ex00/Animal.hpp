/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:52:52 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:05:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(std::string Type);
	Animal(Animal const& obj);
	Animal&	operator=(Animal const& obj);
	virtual	~Animal(void);
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif