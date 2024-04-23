/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:00:05 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/23 10:59:02 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();
		
		Fixed& operator=(const Fixed& rhs);
		
		int getRawBits(void) const;
		void setRawBits(const int raw);

	private:
		int _rawValue;
		static const int _fractionnalBits = 8;
};

#endif