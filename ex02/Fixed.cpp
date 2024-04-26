/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:12:58 by myanez-p          #+#    #+#             */
/*   Updated: 2024/04/26 12:57:06 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Verifier toutes les fonctions et si il y a besoin d'utiliser le getter ou pas

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

bool Fixed::operator>(const Fixed& rhs){
	return this->_rawValue > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs){
	return this->_rawValue < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs){
	return this->_rawValue >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs){
	return this->_rawValue <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs){
	return this->_rawValue == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs){
	return this->_rawValue != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs){
	Fixed	result;
	
	result._rawValue = this->_rawValue + rhs._rawValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs){
	Fixed	result;
	
	result._rawValue = this->_rawValue - rhs._rawValue;
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs){
	Fixed	result;
	
	result._rawValue = (this->_rawValue * rhs._rawValue) / (1<<_fractionnalBits);
	return result;
}
		
Fixed Fixed::operator/(const Fixed& rhs){
	Fixed	result;
	
	result = this->toFloat() / rhs.toFloat();
	return result;
}

//à implémenter
//Fixed& Fixed::operator++(){}

//à implémenter
//Fixed Fixed::operator++(int){}

//à implémenter
//Fixed& Fixed::operator--(){}

//à implémenter
//Fixed Fixed::operator--(int){}

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

//checker le static
Fixed	Fixed::min(Fixed& n1, Fixed& n2){
	if (n1._rawValue < n2._rawValue)
		return n1;
	return n2;
}

//checker le static
Fixed	Fixed::min(const Fixed& n1, const Fixed& n2){
	if (n1._rawValue < n2._rawValue)
		return n1;
	return n2;
}

//checker le static
Fixed	Fixed::max(Fixed& n1, Fixed& n2){
	if (n1._rawValue > n2._rawValue)
		return n1;
	return n2;
}

//checker le static
Fixed	Fixed::max(const Fixed& n1, const Fixed& n2){
	if (n1._rawValue > n2._rawValue)
		return n1;
	return n2;
}