/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:47:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:22:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors and destructor
WrongAnimal::WrongAnimal(void) : _type("") {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	return ;
}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal " << _type << " constructor called!" << std::endl;
	return ;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	return ;
}
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called!" << std::endl;
	return ;
}

// Operator overloads
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
std::string	WrongAnimal::getType(void) const {
	return (_type);
}
void		WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal " << _type << " says: \"...\"" << std::endl;
	return ;
}