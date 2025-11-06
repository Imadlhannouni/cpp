/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:07 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 16:51:01 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string var1 = "HI THIS IS BRAIN";
	std::string *ptr = &var1;
	std::string &ref = var1;
	
	std::cout << &var1 << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	std::cout << var1 << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}