/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:03:07 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:04:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Default constructor
Weapon::Weapon() {
	return ;
}

// Default constructor
Weapon::Weapon(const std::string initialType) {
	_type = initialType;
	return ;
}

// Destructor
Weapon::~Weapon() {
	return ;
}

// Setters
void	Weapon::setType(const std::string newType) {
	_type = newType;
	return ;
}

// Getters
const std::string&	Weapon::getType(void) const {
	return (_type);
}
