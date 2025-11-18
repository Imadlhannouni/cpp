/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:00:44 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 21:10:03 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap c2("Scav");
	ScavTrap c3(c2);

	c2.attack("bot2");
	c2.takeDamage(3);
	c2.beRepaired(5);
	c2.guardGate();
	c3.attack("bot2");
}