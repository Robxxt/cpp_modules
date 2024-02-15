/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:03:30 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/26 15:34:14 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

void	testSwap()
{
	std::cout << "> testSwap" << std::endl;
	int	aInt = 10;
	int	bInt = 20;
	std::cout << "Int" << std::endl;
	std::cout << "\tBefore: " << "[a : " << aInt << ", b : " << bInt << "]" << std::endl;
	swap(aInt, bInt);
	std::cout << "\tAfter: " << "[a : " << aInt << ", b : " << bInt << "]" << std::endl;
	float	aFloat = 10.15;
	float	bFloat = 20.20;
	std::cout << "Float" << std::endl;
	std::cout << "\tBefore: " << "[a : " << aFloat << ", b : " << bFloat << "]" << std::endl;
	swap(aFloat, bFloat);
	std::cout << "\tAfter: " << "[a : " << aFloat << ", b : " << bFloat << "]" << std::endl;
	char	aChar = 'a';
	char	bChar = 'v';
	std::cout << "Char" << std::endl;
	std::cout << "\tBefore: " << "[a : " << aChar << ", b : " << bChar << "]" << std::endl;
	swap(aChar, bChar);
	std::cout << "\tAfter: " << "[a : " << aChar << ", b : " << bChar << "]" << std::endl;
	std::string	aStr = "hola";
	std::string	bStr = "mundo";
	std::cout << "Str" << std::endl;
	std::cout << "\tBefore: " << "[a : " << aStr << ", b : " << bStr << "]" << std::endl;
	swap(aStr, bStr);
	std::cout << "\tAfter: " << "[a : " << aStr << ", b : " << bStr << "]" << std::endl;
}

void	testMin()
{
	std::cout << "> testMin" << std::endl;
	int	aInt = 10;
	int	bInt = 20;
	std::cout << "\tINT a : " << aInt << " b: " << bInt << " => " << min(aInt, bInt) << std::endl;
	float	aFloat = 20.17;
	float	bFloat = 20.19;
	std::cout << "\tFLOAT a : " << aFloat << " b: " << bFloat << " => " << min(aFloat, bFloat) << std::endl;
	char	aChar = 'a';
	char	bChar = 'b';
	std::cout << "\tCHAR a : " << aChar << " b: " << bChar << " => " << min(aChar, bChar) << std::endl;

}

void	testMax()
{
	std::cout << "> testMax" << std::endl;
	int	aInt = 10;
	int	bInt = 20;
	std::cout << "\tINT a : " << aInt << " b: " << bInt << " => " << max(aInt, bInt) << std::endl;
	float	aFloat = 20.17;
	float	bFloat = 20.19;
	std::cout << "\tFLOAT a : " << aFloat << " b: " << bFloat << " => " << max(aFloat, bFloat) << std::endl;
	char	aChar = 'a';
	char	bChar = 'b';
	std::cout << "\tCHAR a : " << aChar << " b: " << bChar << " => " << max(aChar, bChar) << std::endl;

}

int	main(void)
{
	testSwap();
	testMin();
	testMax();
	return (0);
}