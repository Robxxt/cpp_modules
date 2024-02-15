/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:21:51 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 21:34:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
protected:
	std::string	type;
public:
	WrongCat(void);
	WrongCat(std::string Type);
	WrongCat(WrongCat const& obj);
	WrongCat&	operator=(WrongCat const& obj);
	~WrongCat(void);
	void	makeSound(void) const;
};

#endif