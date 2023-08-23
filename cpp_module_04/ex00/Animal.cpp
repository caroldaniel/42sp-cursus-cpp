/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:24:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:21:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor and destructor
Animal::Animal(void) : _type(""){
	std::cout << "Default animal constructed!" << std::endl;
	return ;
}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal " << _type << " constructed!" << std::endl;
	return ;
}
Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal " << _type << " copy constructed!" << std::endl;
	return ;
}
Animal::~Animal(void) {
	std::cout << "Animal " << _type << " destructed!" << std::endl;
	return ;
}

// Operator overloads
Animal	&Animal::operator=(const Animal& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
std::string	Animal::getType(void) const {
	return (_type);
}
void	Animal::makeSound(void) const {
	std::cout << "Animal ";
	if (_type != "")
		std::cout << _type << " ";
	std::cout << "says: \"...\"" << std::endl;
	return ;
}
