/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:01:39 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/30 19:59:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie(void) {
	std::cout << GREEN << "\tDefault Zombie created." << RESET << std::endl;
}

// Parameterized constructor
Zombie::Zombie(std::string name) {
	setName(name);
	std::cout << GREEN << "\tZombie " << _name << " created." << RESET << std::endl;
}

// Destructor
Zombie::~Zombie(void) {
	std::cout << RED << "\tZombie " << _name << " destroyed." << RESET << std::endl;
}

// Setters
void	Zombie::setName(std::string name) {
	_name = name;
}

// Getters
std::string	Zombie::getName(void) {
	return (_name);
}

// Member functions
void	Zombie::announce(void) {
	std::cout << YELLOW << "\t" << _name << ": BraiiiiiiinnnzzzZ...";
	std::cout << RESET << std::endl;
}
