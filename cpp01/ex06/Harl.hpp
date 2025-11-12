/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:33:05 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/07 14:38:26 by ilhannou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HARL_H
# define HARL_H

#include <iostream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		void complain(std::string level);
};

#endif