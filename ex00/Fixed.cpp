/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:00:01 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/20 11:57:50 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*----------------------------------------------------------------*/
/* Constructors and destructors */

Fixed::Fixed(void) : _rawValue(0){
	std::cout << "Default constructor called" << std::endl;
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

/*----------------------------------------------------------------*/
/* Overloaded operators */

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawValue = rhs.getRawBits();
	return *this;
}
