/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:46:27 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 21:07:54 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points == 0)
	{
		std::cout << "No energy points left" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " Shoot " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
	std::cout << "Energy points : " << this->energy_points << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate Keeper Mode" << std::endl;
}