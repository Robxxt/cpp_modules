/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:36:04 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 13:11:22 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _size(0), _list(new int [0]) {}

Span::Span(unsigned int N) : _N(N), _size(0), _list(new int [N]) {}

Span::Span(const Span& s) : _N(s._N), _size(s._size), _list(new int [_N]), _max(s._max), _min(s._min)
{
	for (unsigned int i = 0; i < s._size; i++)
	{
		_list[i] = s._list[i];
	}
}

void	Span::addNumber(int n)
{
	(void)n;
	if (_size >= _N)
		throw std::out_of_range("The list is full");
	_list[_size] = n;
	_size++;
}

void	Span::print() const
{
	for	(unsigned int i = 0; i < _size; i++)
		std::cout << _list[i] << std::endl;
}

Span::~Span() { delete [] _list; }