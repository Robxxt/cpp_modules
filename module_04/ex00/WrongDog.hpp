/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:08:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:35:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
protected:
	std::string	type;
public:
	WrongDog(void);
	WrongDog(std::string Type);
	WrongDog(WrongDog const& obj);
	WrongDog&	operator=(WrongDog const& obj);
	~WrongDog(void);
	void	makeSound(void) const;
};

#endif