/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:21:33 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:49:56 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string Type);
	WrongAnimal(WrongAnimal const& obj);
	WrongAnimal&	operator=(WrongAnimal const& obj);
	~WrongAnimal(void);
	void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif