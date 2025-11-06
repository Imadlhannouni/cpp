/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:35:01 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/02 19:04:15 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string firstname, lastname, nickname, phonenumber, darkestsecret;
	public:
		void setFirstName(const std::string &first);
		void setLastName(const std::string &last);
		void setNickName(const std::string &nick);
		void setPhone(const std::string &number);
		void setSecret(const std::string &secret);

		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setinfo(std::string &firstn, std::string &lastn, std::string &nickn, std::string &phone, std::string &secret);
		std::string truncate(std::string &str);
		void showC() const;
		void display();
};

#endif
