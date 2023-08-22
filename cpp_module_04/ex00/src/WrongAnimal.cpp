/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:47:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:54:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors and destructor
WrongAnimal::WrongAnimal(void) : type("") {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	return ;
}
WrongAnimal::WrongAnimal(std::string wrongAnimal_type) : type(wrongAnimal_type) {
	std::cout << "WrongAnimal " << type << " constructor called!" << std::endl;
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
	type = other.type;
	return (*this);
}

// Member functions
std::string	WrongAnimal::getType(void) const {
	return (type);
}
void		WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal " << type << " says: \"...\"" << std::endl;
	return ;
}