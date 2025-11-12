/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:45:08 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/11 14:46:18 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int i_value)
{
	value = i_value * (1 << fractional_bits);
}

Fixed::Fixed(const float f_value)
{
	value = roundf(f_value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	this->value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed& other) const
{
		return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const
{
		return (this->toFloat() > other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const
{
		return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const
{
		return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const
{
		return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const
{
		return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;;
	result.value = this->value + other.value;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;;
	result.value = this->value - other.value;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.value = (this->value * other.value) >> fractional_bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.value = (this->value << fractional_bits) / other.value;
	return (result);
}

Fixed Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	this->value += 1;
	return (temp);
}

Fixed Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->value -= 1;
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed::~Fixed() {}

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
	return (this->value);
}

void Fixed::setrawBits(int const raw)
{
	this->value = raw;
}