/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:51:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/07 16:52:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

App::App(void) {}

App::~App(void) {}

void	App::run(void)
{
	welcome();
	initPrompt();
}

void	App::welcome(void)
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Welcome to MY AWESOME PHONEBOOK!" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	App::initPrompt(void)
{
	std::string	cmd;
	PhoneBook phoneBookList;

	while (true)
	{
		std::cout << "INPUT> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cerr << "Error reading input. Exiting." << std::endl;
			return ;
		}
		else if (cmd == "ADD")
		{
			Contact contact;
			contact.readContact();
			phoneBookList.addContact(contact);
		}
		else if (cmd == "SEARCH")
		{
			phoneBookList.searchContact();
		}
		else if (cmd == "EXIT")
		{
			std::cout << "GOOD BYE ..." << std::endl;
			break ;
		}
		else if (cmd.length() == 0)
		{
			continue ;
		}
		else
		{
			std::cerr << "[ERROR]: WRONG CMD\nUSE [ADD/SEARCH/EXIT]" << std::endl;
		}
	}
}
