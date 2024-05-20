/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:27 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/20 12:16:24 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*----------------------------------------------------------------*/
/* Constructors and destructors */

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

/*----------------------------------------------------------------*/
/* Tools */

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawValue;
}

void	Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawValue = raw;
}

float 	Fixed::toFloat(void) const{
	return static_cast<float>(this->_rawValue) / static_cast<float>(1 << _fractionnalBits);
}

int 	Fixed::toInt(void) const{
	return this->_rawValue >> _fractionnalBits;
}

/*----------------------------------------------------------------*/
/* Overloaded operators */

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawValue = rhs.getRawBits();
	return *this;
}

/*----------------------------------------------------------------*/
/* Stream operator */

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return o;
}