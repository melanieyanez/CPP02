/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:49 by melanieyane       #+#    #+#             */
/*   Updated: 2024/04/23 11:23:38 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void){
	
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.ToInt() << " as integer " << std::endl;
	std::cout << "b is " << b.ToInt() << " as integer " << std::endl;
	std::cout << "c is " << c.ToInt() << " as integer " << std::endl;
	std::cout << "d is " << d.ToInt() << " as integer " << std::endl;

	return 0;
}