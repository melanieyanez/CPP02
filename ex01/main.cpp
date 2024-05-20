/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:49 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/20 12:37:44 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void){
	
	std::cout << "*************************************************************************" << std::endl;
	std::cout << "*Subject tests*" << std::endl << std::endl;
	
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer " << std::endl;
	std::cout << "b is " << b.toInt() << " as integer " << std::endl;
	std::cout << "c is " << c.toInt() << " as integer " << std::endl;
	std::cout << "d is " << d.toInt() << " as integer " << std::endl;
	
	return 0;
}