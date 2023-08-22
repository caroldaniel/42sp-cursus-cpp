/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:06:48 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 21:13:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor and destructor
FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructed!" << std::endl;
	return ;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed!" << std::endl;
	return ;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << _name << " copy constructed!" << std::endl;
	return ;
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destructed!" << std::endl;
	return ;
}

// Member functions
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " says: \"High five, guys!\"" << std::endl;
	return ;
}
