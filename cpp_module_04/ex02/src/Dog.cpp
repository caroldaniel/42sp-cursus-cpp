/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:28:55 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 12:25:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor and destructor
Dog::Dog(void) : AAnimal("Dog") {
	std::cout << "Dog constructed!" << std::endl;
	_brain = new Brain();
	return ;
}
Dog::Dog(const Dog& other) : AAnimal(other) {
	if (this == &other)
		return ;
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}
Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

// Operator overloads
Dog	&Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
void	Dog::makeSound(void) const {
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}
