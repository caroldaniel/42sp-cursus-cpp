/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:16:42 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:23:26 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor and destructor
HumanB::HumanB(const std::string initialName) : _name(initialName) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

// Methods
void	HumanB::attack(void) const {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(const Weapon& newWeapon) {
	_weapon = &newWeapon;
	return ;
}
