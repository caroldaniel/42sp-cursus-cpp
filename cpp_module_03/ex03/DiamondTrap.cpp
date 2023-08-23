/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:57:07 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:08:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor and destructor
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "Default";
	ClapTrap::_name = "Default_clap_name";
	std::cout << "Default DiamondTrap constructed!" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << DiamondTrap::_name << " constructed!" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << "DiamondTrap " << _name << " copy constructed!" << std::endl;
	return ;
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " destructed!" << std::endl;
	return ;
}

// Operator overloads
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

// Getters
std::string	DiamondTrap::getName(void) {
	return (this->_name);
}
std::string	DiamondTrap::getClapName(void) {
	return (ClapTrap::_name);
}
int			DiamondTrap::getHitPoints(void) {
	return (this->_hitPoints);
}
int			DiamondTrap::getEnergyPoints(void) {
	return (this->_energyPoints);
}
int			DiamondTrap::getAttackDamage(void) {
	return (this->_attackDamage);
}

// Member functions
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap " << _name << " says: \"My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << "!\"" << std::endl;
	return ;
}