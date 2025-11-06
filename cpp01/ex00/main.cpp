/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:40:56 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 16:07:55 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	Zombie *zombie = newZombie(argv[1]);
	zombie->announce();
	
	delete(zombie);

	randomChump(argv[1]);
}