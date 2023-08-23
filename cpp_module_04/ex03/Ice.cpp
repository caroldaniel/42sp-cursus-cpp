/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:06:20 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:26:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors and destructor
Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice constructed!" << std::endl;
	return ;
}
Ice::Ice(const Ice &source) : AMateria(source) {
	std::cout << "Ice copy constructed!" << std::endl;
	return ;
}
Ice::~Ice(void) {
	std::cout << "Ice destructed!" << std::endl;
	return ;
}

// Operator overloads
Ice	&Ice::operator=(const Ice &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member functions
AMateria	*Ice::clone(void) const {
	return (new Ice(*this));
}
void Ice::use(ICharacter& target) {
	std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	return ;
}
