/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:36:56 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/07 14:50:36 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string tab[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*func[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	for (int i = 0; i < 4; i++)
	{
		if (tab[i] == level)
			(this->*func[i])();
	}
}

