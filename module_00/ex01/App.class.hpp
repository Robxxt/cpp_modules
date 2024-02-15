/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:51:48 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/05 12:57:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class	App
{
	public:
		App(void);
		~App(void);
		void	welcome(void);
		void	initPrompt(void);
		void	run(void);
};
