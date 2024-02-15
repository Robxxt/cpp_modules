/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:40:08 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/10 10:46:17 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("warning");
	harl.complain("debug");
	harl.complain("info");
	harl.complain("error");
	return (0);
}
