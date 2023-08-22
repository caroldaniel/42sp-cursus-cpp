/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:57:07 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 23:14:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor and destructor
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	_name = "Default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default DiamondTrap constructed!" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name.append("_clap_name")), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
	return ;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap " << _name << " copy constructed!" << std::endl;
	return ;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destructed!" << std::endl;
	return ;
}

// Member functions
void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << _name << " says: \"My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << "!\"" << std::endl;
	return ;
}
