/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:23:27 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/18 17:02:14 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : ScavTrap, FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		void attack(std::string &target);
		void whoAmI();
};

#endif