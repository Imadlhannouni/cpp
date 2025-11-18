/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:23:25 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 17:02:05 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->Name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Diamond Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamon Trap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond name : " << this->Name << std::endl;
	std::cout << "Clap name : " << ClapTrap::Name << std::endl;
}