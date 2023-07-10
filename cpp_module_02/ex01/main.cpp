/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:41:53 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 18:16:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	// declare a variable of type Fixed
	Fixed a;
	// declare another variable of type Fixed with a int value
	Fixed const b(10);
	// declare another variable of type Fixed with a float value
	Fixed const c(42.42f);
	// declare a copy of Fixed b
	Fixed const d(b);
	// assign new Fixed to a
	a = Fixed(1234.4321f);
	// compare the values of a and b
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}
