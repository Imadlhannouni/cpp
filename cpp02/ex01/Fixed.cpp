/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:45:08 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/09 16:48:19 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_value)
{
	std::cout << "Int constructor called" << std::endl;
	value = i_value * (1 << fractional_bits);
}

Fixed::Fixed(const float f_value)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(f_value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

float Fixed::toFloat() const
{
	return (float)value / (1 << fractional_bits);
}

int Fixed::toInt() const
{
	return (int)value >> fractional_bits;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setrawBits(int const raw)
{
	this->value = raw;
}