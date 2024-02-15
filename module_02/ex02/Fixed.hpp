/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:59:41 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/15 17:01:38 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &obj);
	~Fixed(void);
	bool	operator<(Fixed const &obj) const;
	bool	operator<=(Fixed const &obj) const;
	bool	operator>(Fixed const &obj) const;
	bool	operator>=(Fixed const &obj) const;
	bool	operator==(Fixed const &obj) const;
	bool	operator!=(Fixed const &obj) const;
	Fixed&	operator*(Fixed const &obj);
	static Fixed	min(Fixed const &obj1, Fixed const &obj2);
	static Fixed	min(Fixed &obj1, Fixed &obj2);
	static Fixed	max(Fixed const &obj1, Fixed const &obj2);
	static Fixed	max(Fixed &obj1, Fixed &obj2);
	// Prefix operator ++var
	Fixed&	operator++(void);
	// Postfix operator var++
	Fixed	operator++(int);
	Fixed&	operator=(Fixed const &obj);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& OUT, Fixed const& fixed);

#endif