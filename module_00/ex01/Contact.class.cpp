/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:42:26 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/07 16:55:19 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(std::string fName,
				std::string lName,
				std::string nName,
				std::string pNumber,
				std::string dSecret) :	firstName(fName), lastName(lName), nickName(nName),
												phoneNumber(pNumber), darkestSecret(dSecret)
{}

Contact::~Contact(void) {}

void	Contact::printReducedInfoContact(void)
{
	Contact	contact;

	printFormattedText(firstName);
	std::cout << "|";
	printFormattedText(lastName);
	std::cout << "|";
	printFormattedText(nickName);
	std::cout << "|";
	printFormattedText(phoneNumber);
	std::cout << std::endl;
}

void	Contact::printContact(void)
{
	std::cout << "-------------" << std::endl;
	std::cout << "CONTACT QUERY" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "firstName: " << firstName << std::endl;
	std::cout << "lastName: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "phoneNumber: " << phoneNumber << std::endl;
	std::cout << "darkestSecret: " << darkestSecret << std::endl;
}
void	Contact::readContact(void)
{

	while (isEmpyt(firstName))
	{
		std::cout << "firstName: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return ;
	}
	
	while (isEmpyt(lastName))
	{
		std::cout << "lastName: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return ;
	}
	
	while (isEmpyt(nickName))
	{
		std::cout << "nickName: ";
		std::getline(std::cin, nickName);
		if (std::cin.eof())
			return ;
	}

	while (isEmpyt(phoneNumber))
	{
		std::cout << "phoneNumber: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return ;
	}

	while (isEmpyt(darkestSecret))
	{
		std::cout << "secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return ;
	}
}