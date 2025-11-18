/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:45:58 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 21:04:11 by ilhannou         ###   ########.fr       */
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

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage) 
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->Name = other.Name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "ClapTrap Assignement operator called" << std::endl;

	return (*this);
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
	std::cout << "ClapTrap " << this->Name << " has been attacked, with " << amount << " damgage" << std::endl;
	this->hit_points -= amount;
	std::cout << "Health : " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " repair himself with " << amount << std::endl;
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "Health : " << this->hit_points << std::endl;
	std::cout << "Energy points : " << this->energy_points << std::endl;
}