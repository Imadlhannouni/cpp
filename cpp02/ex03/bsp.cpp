/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:54:32 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/12 16:23:28 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed Fixed::abs() const
{
	if (this->getRawBits() < 0)
		return (Fixed(-this->toFloat()));
	return (*this);
}

Fixed area(Point const &p1, Point const &p2, Point const &p3) {
    return Fixed(
        (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
         p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
         p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))
        / 2.0f
    ).abs();
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed areaABC = area(a, b, c);
	Fixed areaABP = area(a, b, point);
	Fixed areaACP = area(a, c, point);
	Fixed areaBCP = area(b, c, point);

	if (areaABP == 0 || areaACP == 0 || areaBCP == 0)
		return (false);
	
	return (areaABC == areaABP + areaACP + areaBCP);
}