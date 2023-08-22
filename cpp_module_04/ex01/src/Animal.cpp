/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:24:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:44:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor and destructor
Animal::Animal(void) : type(""){
	std::cout << "Default animal constructed!" << std::endl;
	return ;
}
Animal::Animal(std::string animal_type) : type(animal_type) {
	std::cout << "Animal " << type << " constructed!" << std::endl;
	return ;
}
Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal " << type << " copy constructed!" << std::endl;
	return ;
}
Animal::~Animal(void) {
	std::cout << "Animal " << type << " destructed!" << std::endl;
	return ;
}

// Operator overloads
Animal	&Animal::operator=(const Animal& other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

// Member functions
std::string	Animal::getType(void) const {
	return (type);
}
void	Animal::makeSound(void) const {
	std::cout << "Animal ";
	if (type != "")
		std::cout << type << " ";
	std::cout << "says: \"...\"" << std::endl;
	return ;
}
