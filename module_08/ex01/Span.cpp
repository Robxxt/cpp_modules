/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:04:31 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/29 12:49:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span() : _arr(new std::list<int>[0]), _N(0), _size(0) {}

Span::Span(unsigned int N) : _arr(new std::list<int>[N]), _N(N), _size(0) {}

Span::Span(const Span& s) : _arr(new std::list<int>[s._N]), _N(s._N), _size(s._size)
{
	for (unsigned int i = 0; i < s._size; i++)
	{
		_arr[i] = s._arr[i];
	}
}

Span&	Span::operator=(const Span& s)
{
	if (this != &s)
	{
		_arr = new std::list<int>[s._N];
		_N = s._N;
		_size = s._size;
		for (unsigned int i = 0; i < s._size; i++)
		{
			_arr[i] = s._arr[i];
		}
	}
	return *this;
}

Span::~Span()
{
	delete [] _arr;
}

void	Span::addNumber(int n)
{
	if (_N == 0 || _size >= _N)
	{
		throw std::out_of_range("Can't add any new item to the list");
	}
	_arr->push_back(n);
	++_size;
}

int		Span::shortestSpan()
{
	int	shortest = INT_MAX;

	for (std::list<int>::const_iterator it1 = _arr->begin(); it1 != _arr->end(); ++it1) {
		std::list<int>::const_iterator tmp = it1;
        for (; tmp != _arr->end(); ++tmp) {
            int span = std::abs(*it1 - *tmp);
            if (span < shortest) {
                shortest = span;
            }
        }
    }
	return (shortest);
}

int		Span::longestSpan()
{
	int	min = *(std::min_element(_arr->begin(), _arr->end()));
	int	max = *(std::max_element(_arr->begin(), _arr->end()));
	return (std::abs(min - max));
}

void	Span::addNumbers(int* start, int* end)
{
	while (start != end)
	{
		if (_size >= _N)
		{
			throw std::out_of_range("Can't add any new item to the list");
		}
		addNumber(*start);
		start++;
	}
}


// void	Span::printLst()
// {
// 	std::list<int>::iterator it;

// 	for (it = _arr->begin(); it != _arr->end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
	
// }