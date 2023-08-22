/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:48:52 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:57:55 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors and destructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
	return ;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat copy constructor called!" << std::endl;
	return ;
}
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called!" << std::endl;
	return ;
}

// Operator overloads
WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}