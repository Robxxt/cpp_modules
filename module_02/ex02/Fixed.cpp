/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:27:06 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/15 17:09:54 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(int value)
{
	this->_value = value * 256;
}

Fixed::Fixed(float value)
{
	this->_value = roundf(value * 256);
}

Fixed::Fixed(Fixed const &obj)
{

	*this = obj;
}

Fixed::~Fixed(void)
{
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void		Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (this->_value / 256.0);
}

int		Fixed::toInt( void ) const
{
	return (this->_value / 256);
}

Fixed&	Fixed::operator=(Fixed const &obj)
{
	this->_value = obj._value;
	return (*this);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (this->_value < obj.getRawBits());
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (this->_value <= obj.getRawBits());
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (this->_value > obj.getRawBits());
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (this->_value >= obj.getRawBits());
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (this->_value == obj.getRawBits());
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (this->_value != obj.getRawBits());
}

Fixed&	Fixed::operator*(Fixed const &obj)
{
	this->_value = (this->_value / 256.0) * obj.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator++(void)
{
	++_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++_value;
	return (tmp);
}

Fixed	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

Fixed	Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

Fixed	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

Fixed	Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

std::ostream&	operator<<(std::ostream& OUT, Fixed const& fixed)
{
	OUT << fixed.toFloat();
	return (OUT);
}
