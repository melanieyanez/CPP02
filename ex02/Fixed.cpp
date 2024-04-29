/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:12:58 by myanez-p          #+#    #+#             */
/*   Updated: 2024/04/29 14:18:13 by melanieyane      ###   ########.fr       */
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

/*----------------------------------------------------------------*/
/* Overloaded operators */

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
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs){
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs){
	return Fixed(this->toFloat() * rhs.toFloat());
}
		
Fixed Fixed::operator/(const Fixed& rhs){
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(){
	this->_rawValue++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->_rawValue++;
	return tmp;
}

Fixed& Fixed::operator--(){
	this->_rawValue--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->_rawValue--;
	return tmp;
}

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawValue = rhs.getRawBits();
	return *this;
}

/*----------------------------------------------------------------*/
/* Overloaded member functions */

Fixed	Fixed::min(Fixed& n1, Fixed& n2){
	return (n1 < n2) ? n1 : n2;
}

Fixed	Fixed::min(const Fixed& n1, const Fixed& n2){
	return (n1.getRawBits() > n2.getRawBits()) ? n1 : n2;
}

Fixed	Fixed::max(Fixed& n1, Fixed& n2){
	return (n1 > n2) ? n1 : n2;
}

Fixed	Fixed::max(const Fixed& n1, const Fixed& n2){
	return (n1.getRawBits() > n2.getRawBits()) ? n1 : n2;
}

/*----------------------------------------------------------------*/
/* Stream operator */

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return o;
}