/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:00:44 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 17:03:08 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::string name = "bot2";
	// ClapTrap c1("bot1");
	// ScavTrap c2("Scav");
	// FragTrap c3("Frag");
	DiamondTrap c4("D4");
	
	// c1.attack(name);
	// c1.takeDamage(3);
	// c1.beRepaired(5);

	// c2.attack(name);
	// c2.takeDamage(3);
	// c2.beRepaired(5);
	// c2.guardGate();

	// c3.attack(name);
	// c3.takeDamage(3);
	// c3.beRepaired(5);
	// c3.highFivesGuys();

	c4.attack(name);
	c4.whoAmI();
}