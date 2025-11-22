/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:56:54 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/22 14:12:35 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	this->b = new Brain();
	this->type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(b);
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->b = new Brain(*other.b);
	this->type = other.type;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        *(this->b) = *(other.b);
    }
    std::cout << "Dog Copy assignment called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "HAWWWWWW" << std::endl;
}
