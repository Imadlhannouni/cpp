/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:40:56 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 16:42:39 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
	int n;
	if (argc != 3)
		return (1);
	std::stringstream ss(argv[1]);
	ss >> n;
	Zombie *horde = zombieHorde(n, argv[2]);
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}