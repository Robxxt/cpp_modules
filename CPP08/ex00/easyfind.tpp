/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:25:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 11:53:13 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	easyfind(T lst, int toFind)
{
	typename T::iterator	it;

	for (it = lst.begin(); it != lst.end(); ++it)
	{
		if (*it == (int)toFind)
			return (int)*it;
	}
	throw std::out_of_range("The item that you search is not in in the list");
}