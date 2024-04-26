/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:27 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/24 15:15:12 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer_value) : _rawValue(integer_value << _fractionnalBits) {
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : _rawValue(static_cast<int>(roundf(float_value * (1 << _fractionnalBits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}

void	Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called" << std::endl;
	_rawValue = raw;
}

float 	Fixed::toFloat(void) const{
	return static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionnalBits);
}

int 	Fixed::toInt(void) const{
	return _rawValue >> _fractionnalBits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return o;
}