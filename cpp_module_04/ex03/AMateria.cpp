/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:47:52 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:25:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors and destructor
AMateria::AMateria(void) {
	_type = "default";
	std::cout << "Default AMateria constructed!" << std::endl;
	return ;
}
AMateria::AMateria(std::string const &type) {
	_type = type;
	std::cout << "AMateria of type " << _type << " constructed!" << std::endl;
	return ;
}
AMateria::AMateria(const AMateria &source) {
	*this = source;
	std::cout << "AMateria of type " << _type << " copy constructed!" << std::endl;
	return ;
}
AMateria::~AMateria(void) {
	std::cout << "AMateria destructed!" << std::endl;
	return ;
}

// Operator overloads
AMateria	&AMateria::operator=(const AMateria &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member functions
std::string const	&AMateria::getType(void) const {
	return (this->_type);
}
void AMateria::use(ICharacter& target) {
	std::cout << GREEN << "* " << _type << " uses its powers at " << target.getName() << " *" << RESET << std::endl;
	return ;
}
