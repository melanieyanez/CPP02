/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:13:04 by myanez-p          #+#    #+#             */
/*   Updated: 2024/05/20 13:36:00 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int	main(void) {

	std::cout << "*************************************************************************" << std::endl;
	std::cout << "*Subject tests*" << std::endl << std::endl;
	
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << "*************************************************************************" << std::endl;
	std::cout << "*Additionnal tests*" << std::endl << std::endl;

	std::cout << std::fixed << std::setprecision(8);
	
	Fixed c(21);
	Fixed d(42);
	Fixed e(42);

	std::cout << (c>d) << std::endl;
	std::cout << (c<d) << std::endl;
	std::cout << (c>=d) << std::endl;
	std::cout << (d>=e) << std::endl;
	std::cout << (c<=d) << std::endl;
	std::cout << (c==d) << std::endl;
	std::cout << (d==e) << std::endl;
	std::cout << (c!=d) << std::endl;
	std::cout << (d!=e) << std::endl;

	std::cout << (c+d) << std::endl;
	std::cout << (d-c) << std::endl;
	std::cout << (c*d) << std::endl;
	std::cout << (d/c) << std::endl;

	std::cout << c << std::endl; //c=21
	std::cout << (c++) << std::endl; //incremente et utilise la valeur avant incr c=21
	std::cout << c << std::endl; //valeur après incr c=21.00390625
	std::cout << (c--) << std::endl; //decremente et utilise valeur avant decr c=21.00390625
	std::cout << c << std::endl; //valeur après decr c=21
	std::cout << (++c) << std::endl; //incremente et utilise la valeur après incr c=21.00390625
	std::cout << c << std::endl; //valeur après incr c=21.00390625
	std::cout << (--c) << std::endl; //decremente et utilise valeur après decr c=21
	std::cout << c << std::endl; //valeur après decr c=21

	std::cout << Fixed::min(c,d) << std::endl;
	std::cout << Fixed::max(c,d) << std::endl;

	return 0; 
}