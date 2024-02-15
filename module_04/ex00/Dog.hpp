/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:08:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 20:10:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class	Dog: public Animal
{
protected:
	std::string	type;
public:
	Dog(void);
	Dog(std::string Type);
	Dog(Dog const& obj);
	Dog&	operator=(Dog const& obj);
	~Dog(void);
	void	makeSound(void) const;
};

#endif