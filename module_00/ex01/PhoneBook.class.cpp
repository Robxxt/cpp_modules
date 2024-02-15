/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:35:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/06 14:17:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) : lastContactIndex(-1), oldestContactIndex(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(Contact contact)
{
	if (lastContactIndex >= 7)
	{
		contactList[oldestContactIndex] = contact;
		if (oldestContactIndex > 7)
			oldestContactIndex = 0;
		else
			oldestContactIndex++;
	}
	else
	{
		contactList[lastContactIndex + 1] = contact;
		lastContactIndex++;
	}
}

void	PhoneBook::printAllContacts()
{
	std::cout << "------------" << std::endl;
	std::cout << "Contact List" << std::endl;
	std::cout << "------------" << std::endl;
	printFormattedText("FirstName");
	std::cout << "|";
	printFormattedText("LastName");
	std::cout << "|";
	printFormattedText("NickName");
	std::cout << "|";
	printFormattedText("Tel.");
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < lastContactIndex + 1; i++)
	{
		contactList[i].printReducedInfoContact();
	}
}

void	PhoneBook::searchContact(void)
{
	int	n;

	printAllContacts();
	std::cout << "Total contacts: " << lastContactIndex + 1 << std::endl;
	std::cout << "Contact index: ";
	std::cin >> n;
	if (n >= 0 && n <= 7 && lastContactIndex > -1)
	{
		contactList[n].printContact();
	}
	else
	{
		std::cerr << "[ERROR]: Invalid input!" << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(1000, '\n');

}