/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:48:50 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/10 10:45:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl
{
private:
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	std::string	_options[4];
public:
	void complain(std::string level);
	Harl(void);
	~Harl(void);
};

#endif
