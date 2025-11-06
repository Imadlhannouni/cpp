/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:55:34 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 21:24:59 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *weapon;
		std::string name;
	public:
		void attack();
		void setWeapon(Weapon &weap);
		HumanB(std::string nam);
};

#endif