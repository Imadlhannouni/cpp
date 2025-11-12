/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:40:23 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/11 14:17:18 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Contact.hpp"
#include <iomanip>

void	Contact::setFirstName(const std::string &first) { firstname = first; }
void	Contact::setLastName(const std::string &last) { lastname = last; }
void	Contact::setNickName(const std::string &nick) { nickname = nick; }
void	Contact::setPhone(const std::string &number) { phonenumber = number; }
void	Contact::setSecret(const std::string &secret) { darkestsecret = secret; }

std::string Contact::getFirstname() const { return firstname; }
std::string Contact::getLastname() const { return lastname; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phonenumber; }
std::string Contact::getDarkestSecret() const { return darkestsecret; }

void Contact::setinfo(std::string &firstn, std::string &lastn, std::string &nickn, std::string &phone, std::string &secret)
{
	setFirstName(firstn);
	setLastName(lastn);
	setNickName(nickn);
	setPhone(phone);
	setSecret(secret);
}

std::string Contact::truncate(std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::showC() const 
{
	std::cout << "First name: " << firstname << std::endl;
	std::cout << "Last name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phonenumber << std::endl;
	std::cout << "Darkest secret: " << darkestsecret << std::endl;
}

void Contact::display() {
	std::cout << std::setw(10) << truncate(firstname) << "|";
	std::cout << std::setw(10) << truncate(lastname) << "|";
	std::cout << std::setw(10) << truncate(nickname) << "|" << std::endl;
}