/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:40:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:06:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors and destructor
ScavTrap::ScavTrap(void) : ClapTrap() {
	_name = "Default";
	_energyPoints = 50;
	std::cout << "Default ScavTrap constructed!" << std::endl;
	return ;
}
ScavTrap::ScavTrap(std::string &name) : ClapTrap(name) {
	_name = name;
	_energyPoints = 50;
	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
	return ;
}
ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source) {
	*this = source;
	std::cout << "ScavTrap " << _name << " copy constructed!" << std::endl;
	return ;
}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
	return ;
}

// Operator overloads
ScavTrap	&ScavTrap::operator=(const ScavTrap &source) {
	if (this == &source)
		return (*this);
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return (*this);
}

// Member functions
void	ScavTrap::attack(std::string const &target) {
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	return ;
}
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	return ;
}
