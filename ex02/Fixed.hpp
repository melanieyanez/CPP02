/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:13:01 by myanez-p          #+#    #+#             */
/*   Updated: 2024/04/26 12:53:46 by myanez-p         ###   ########.fr       */
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
		
		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator==(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);
		
		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		
		int 	getRawBits(void) const;
		void 	setRawBits(const int raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;

		Fixed	min(Fixed& n1, Fixed& n2);
		Fixed	min(const Fixed& n1, const Fixed& n2);
		Fixed	max(Fixed& n1, Fixed& n2);
		Fixed	max(const Fixed& n1, const Fixed& n2);

	private:
		int 				_rawValue;
		static const int 	_fractionnalBits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif