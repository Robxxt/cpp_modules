/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:42:35 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/07 16:54:26 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "main.hpp"

class Contact
{
	public:
		Contact(std::string fName="",
				std::string lName="",
				std::string nName="",
				std::string pNumber="",
				std::string dSecret="");
		~Contact(void);
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		void		getContactInfo(void);
		void		printReducedInfoContact(void);
		void		printContact(void);
		void		readContact(void);
};

#endif