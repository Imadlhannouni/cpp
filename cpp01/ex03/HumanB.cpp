/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:55:48 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 21:27:02 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nam)
{
	name = nam;
	weapon = NULL;
}

void HumanB::setWeapon(Weapon &weap)
{
	weapon = &weap;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}