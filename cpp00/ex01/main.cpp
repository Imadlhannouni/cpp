/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:16:32 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/03 01:46:43 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cctype>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int    add_contact(PhoneBook *book)
{
    std::string firstname, lastname, nickname, phonenumber, darkestsecret;

    std::cout << "Firstname : ";
    if (!std::getline(std::cin, firstname))
        return 1;
    std::cout << "Lastname : ";
    if (!std::getline(std::cin, lastname))
        return 1;
    std::cout << "Nickname : ";
    if (!std::getline(std::cin, nickname))
        return 1;
    std::cout << "Phone Number : ";
    if (!std::getline(std::cin, phonenumber))
        return 1;
    std::cout << "Darkest Secret : ";
    if (!std::getline(std::cin, darkestsecret))
        return 1;
    if (firstname.empty() || lastname.empty() || nickname.empty() || 
        phonenumber.empty() || darkestsecret.empty())
    {
        std::cout << "Error: All fields must be filled!" << std::endl;
        return 1;
    }
    book->addContact(firstname, lastname, nickname, phonenumber, darkestsecret);
    std::cout << "Contact added successfully." << std::endl;
    
    return 0;
}

void	search_contact(PhoneBook *book)
{
	int indx;
	char extra;
	std::string input;
	
	std::cout << "Enter an Index to display : ";
	if (!getline(std::cin, input))
		return ;
	std::stringstream ss(input);
	if (!(ss >> indx) || ss.get(extra))
	{
		std::cout << "Enter a valid index." << std::endl;
		return ;
	}
	if (indx >= 0 && indx < 8)
		book->showContact(indx);
	else
		std::cout << "Index invalid" << std::endl;
}

int main()
{
	PhoneBook book;
	std::string command;

	while (1)
	{
		std::cout << "Enter one of the three commands: (ADD - SEARCH - EXIT)" << std::endl;
		if (!std::getline(std::cin, command))
        {
            std::cout << std::endl << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }
		if (command.compare("ADD") == 0)
		{
			if (add_contact(&book))
				return (1);
		}
		else if (command.compare("SEARCH") == 0)
		{
			book.showAll();
			search_contact(&book);
		}
		else if (command.compare("EXIT") == 0)
			return (0);
	}
}