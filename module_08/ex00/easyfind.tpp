/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:00:59 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/29 12:58:27 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

template <typename T>
int	easyFind(T& container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it != container.end())
		return (target);
	throw std::out_of_range("Item not in the list");
}
