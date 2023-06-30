/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:01:39 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/30 20:00:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructors and destructors
Zombie::Zombie(std::string name) {
	setName(name);
	std::cout << GREEN << "\tZombie " << _name << " created." << RESET << std::endl;
}
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
