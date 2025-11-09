/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:05:27 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/09 15:42:14 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();


		int getRawBits() const;
		void setrawBits(int const raw);
};

#endif