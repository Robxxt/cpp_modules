/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:42 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/19 20:37:37 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
public:
	Brain(void);
	~Brain(void);
	Brain(Brain const& obj);
	Brain&	operator=(Brain const& obj);
	std::string	getIdea(int index) const;
	void	setIdeas(void);
private:
	std::string	_ideas[100];
};

#endif