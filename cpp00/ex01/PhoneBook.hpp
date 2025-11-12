/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:08:23 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/12 14:40:14 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int index;
	public:
		PhoneBook() {
			index = 0;
		}
		void addContact(std::string firstn, std::string lastn, std::string nickn, std::string phone, std::string secret);
		void showAll();
		int showContact(int indx) const;
};

#endif