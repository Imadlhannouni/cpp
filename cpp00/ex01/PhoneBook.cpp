/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:09:18 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/02 19:19:07 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::addContact(std::string firstn, std::string lastn, std::string nickn, std::string phone, std::string secret)
{
	contact[index].setinfo(firstn, lastn, nickn, phone, secret);
	index = (index + 1) % 8;
}

void PhoneBook::showAll() {
	for (int i = 0; i < 8; i++)
	{
		std::cout << "Index: " << i << " | ";
		contact[i].display();
	}
}

void PhoneBook::showContact(int indx) const
{
	contact[indx].showC();
}
