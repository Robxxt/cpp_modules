/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:58 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/19 15:14:35 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <cmath>
# include <iostream>

class	Span
{
	private:
		unsigned int	_N;
		unsigned int	_size;
		int*			_list;
		int				_max;
		int				_min;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& s);
		Span&	operator=(const Span& s);
		~Span();
		void	addNumber(int n);
		void	print() const;
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRange(unsigned int end);
};

#endif