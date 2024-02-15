/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:03:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/27 13:12:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <climits>
# include <algorithm>
# include <list>
# include <iostream>

class Span
{
private:
	std::list<int>	*_arr;
	unsigned int	_N;
	unsigned int	_size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& s);
	Span&	operator=(const Span& s);
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	// void	printLst(); // REMOVE
	void	addNumbers(int* start, int* end);
	~Span();
};

#endif