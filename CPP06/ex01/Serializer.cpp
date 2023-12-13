/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:26:38 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 18:08:10 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer& s) {(void)s;}

Serializer&	Serializer::operator=(const Serializer& s)
{
	(void)s;
	return *this;
}

Serializer::~Serializer() {};

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	newPtr = reinterpret_cast<uintptr_t>(ptr);
	return newPtr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data*	newPtr = reinterpret_cast<Data*>(raw);
	return newPtr;
}
