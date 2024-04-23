/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:27 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/23 11:37:48 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawValue(0){
	std::cout << "Default constructor called" << std::endl;
}

//à implémenter
Fixed::Fixed(const int integer_value){}

//à implémenter
Fixed::Fixed(const float float_value){}

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

//à implémenter
float 	Fixed::toFloat(void) const{}

//à implémenter
int 	Fixed::toInt(void) const{}

//à implémenter
std::ostream& operator<<(std::ostream& o, const Fixed& fixed){}