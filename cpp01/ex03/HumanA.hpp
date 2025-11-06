/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:51:54 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 21:40:05 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &weapon;
		std::string name;
	public:
		void attack();
		HumanA(std::string nam, Weapon &weap);
};

#endif