/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:37 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/23 11:33:31 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	
	public:
		Fixed();
		Fixed(const int integer_value);
		Fixed(const float float_value);
		Fixed(const Fixed& src);
		~Fixed();
		
		Fixed& operator=(const Fixed& rhs);
		
		int 	getRawBits(void) const;
		void 	setRawBits(const int raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;

	private:
		int 				_rawValue;
		static const int 	_fractionnalBits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif