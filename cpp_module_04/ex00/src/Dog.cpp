/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:28:55 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:40:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor and destructor
Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog constructed!" << std::endl;
	return ;
}
Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}
Dog::~Dog(void) {
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

// Operator overloads
Dog	&Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

// Member functions
void	Dog::makeSound(void) const {
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}
