/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:09:18 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/11 14:14:48 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::addContact(std::string firstn, std::string lastn, std::string nickn, std::string phone, std::string secret)
{
	contact[index].setinfo(firstn, lastn, nickn, phone, secret);
	index = (index + 1) % 8;
}

void PhoneBook::showAll() {
	std::cout << "Index| First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].getFirstname().empty())
			break ;
		std::cout << "    " << i << "| ";
		contact[i].display();
	}
}

int PhoneBook::showContact(int indx) const
{
	if (contact[indx].getFirstname().empty())
		return (1);
	contact[indx].showC();
	return (0);
}
