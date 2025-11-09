/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:05:27 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/09 16:48:27 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int i_value);
		Fixed(const float f_value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		friend std::ostream& operator<<(std::ostream& os, const Fixed &f);


		int getRawBits() const;
		void setrawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

#endif