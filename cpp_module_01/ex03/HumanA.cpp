/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:06:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:23:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor and destructor
HumanA::HumanA(const std::string initialName, Weapon& initialWeapon) 
	: _name(initialName), _weapon(initialWeapon){
	return ;
}

HumanA::~HumanA() {
	return ;
}

// Methods
void	HumanA::attack(void) const {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}
