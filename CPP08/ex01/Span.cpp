/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:36:04 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 13:43:18 by rdragan          ###   ########.fr       */
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
	if (_size >= _N || _N == 0)
		throw std::out_of_range("The list is full");
	if (_size == 0)
	{
		_max = n;
		_min = n;
	}
	else if (_min > n)
		_min = n;
	else if (_max < n)
		_max = n;
	_list[_size] = n;
	_size++;
}

void	Span::print() const // TO REMOVE
{
	if (_size == 0)
	{
		std::cerr << "The list doesn't have any element" << std::endl;
		return ;
	}
	std::cout << "MAX: " << _max << std::endl;
	std::cout << "MIN: " << _min << std::endl;
	for	(unsigned int i = 0; i < _size; i++)
		std::cout << _list[i] << std::endl;
}

int		Span::shortestSpan() const
{
	return (0);
}

int		Span::longestSpan() const
{
	return (_max - _min);
}


Span::~Span() { delete [] _list; }