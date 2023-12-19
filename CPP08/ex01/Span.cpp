/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:36:04 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 15:08:14 by rdragan          ###   ########.fr       */
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

Span&	Span::operator=(const Span& s)
{
	if (this != &s)
	{
		_N = s._N;
		_size = s._size;
		_max = s._max;
		_min = s._min;
		_list = new int [_N];
		for (unsigned int i = 0; i < s._size; i++)
		{
			_list[i] = s._list[i];
		}
	}
	return (*this);
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
	std::cout << "SIZE: " << _size << std::endl;
	std::cout << "MAX: " << _max << std::endl;
	for	(unsigned int i = 0; i < _size; i++)
		std::cout << _list[i] << std::endl;
}

int		Span::shortestSpan() const
{
	int	shortest;
	int	tmp;

	if (_size <= 1)
		throw std::out_of_range("You don't have enough items to perform longestSpan opperation");
	shortest = abs(_list[0] - _list[1]);
	for (unsigned i = 0; i < _size - 1; i++)
	{
		tmp = abs(_list[i] - _list[i + 1]);
		shortest = (shortest > tmp) ? tmp : shortest;
	}
	
	return (shortest);
}

int		Span::longestSpan() const
{
	if (_size <= 1)
		throw std::out_of_range("You don't have enough items to perform longestSpan opperation");
	return (_max - _min);
}

void	Span::addRange(unsigned int N)
{
	if (N > _N)
		throw std::out_of_range("Too many items for the size of this Span");
	for (int *it = _list; it != _list + N; ++it)
	{
		addNumber(static_cast<int>(it - _list));
	}
}

Span::~Span() { delete [] _list; }