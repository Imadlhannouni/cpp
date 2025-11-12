/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:06:50 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/12 16:29:42 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point A(0, 0);
    Point B(4, 0);
    Point C(0, 3);
    Point P(0, 3);

    if (bsp(A, B, C, P))
        std::cout << "P is inside the triangle\n";
    else
        std::cout << "P is outside the triangle\n";

    return 0;
}