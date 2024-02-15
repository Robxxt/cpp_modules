/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:19:51 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/18 20:10:55 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class	Cat: public Animal
{
protected:
	std::string	type;
public:
	Cat(void);
	Cat(std::string Type);
	Cat(Cat const& obj);
	Cat&	operator=(Cat const& obj);
	~Cat(void);
	void	makeSound(void) const;
};

#endif