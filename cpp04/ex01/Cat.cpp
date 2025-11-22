/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:52:05 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/22 14:12:42 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->b = new Brain();
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(b);
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->b = new Brain(*other.b);
	this->type = other.type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        *(this->b) = *(other.b);
    }
    std::cout << "Cat Copy assignment called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIAWWWWW" << std::endl;
}
