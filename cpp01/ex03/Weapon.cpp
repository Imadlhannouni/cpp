/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:47:07 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 21:15:55 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typ)
{
	type = typ;
}

void Weapon::setType(std::string ty)
{
	type = ty;
}

const std::string &Weapon::getType() const {
	return type;
}
