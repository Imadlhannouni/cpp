/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:45:58 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/13 14:05:19 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points == 0)
	{
		std::cout << "No energy points left" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
	std::cout << "Energy points : " << this->energy_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap has been attacked, with " << amount << " damgage" << std::endl;
	this->hit_points -= amount;
	std::cout << "Health : " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap repair himself with " << amount << std::endl;
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "Health : " << this->hit_points << std::endl;
	std::cout << "Energy points : " << this->energy_points << std::endl;
}