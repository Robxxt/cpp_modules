/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:39:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/26 15:48:21 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* arr, int length, void (*func)(T& element))
{
	for (int i = 0; i < length; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void	iter(const T* arr, int length, void (*func)(const T& element))
{
	for (int i = 0; i < length; i++)
	{
		func(arr[i]);
	}
}

#endif