/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:00:08 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/20 12:33:07 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void){
	
	std::cout << "*************************************************************************" << std::endl;
	std::cout << "*Subject tests*" << std::endl << std::endl;
	
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << "*************************************************************************" << std::endl;
	std::cout << "*Additionnal tests*" << std::endl << std::endl;
	
	Fixed	d;

	std::cout << d.getRawBits() << std::endl;
	c.setRawBits(12);
	std::cout << c.getRawBits() << std::endl;
	d = c;
	std::cout << d.getRawBits() << std::endl;

	return 0;
}