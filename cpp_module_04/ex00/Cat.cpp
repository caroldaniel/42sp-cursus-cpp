/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:30:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:21:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor and destructor
Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat constructed!" << std::endl;
	return ;
}
Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << "Cat copy constructed!" << std::endl;
	return ;
}
Cat::~Cat(void) {
	std::cout << "Cat destructed!" << std::endl;
	return ;
}

// Operator overloads
Cat	&Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
void	Cat::makeSound(void) const {
	std::cout << "Cat says: \"Meow!\"" << std::endl;
	return ;
}
