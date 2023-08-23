/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 19:43:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	std::cout << GREEN << std::endl << "----- Constructor calls -----" << RESET << std::endl;
	DiamondTrap diamond("Diamond");
	
	std::cout << GREEN << std::endl << "----- Get attributes -----" << RESET << std::endl;
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "ClapTrapName: " << diamond.getClapName() << std::endl;
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;
	
	std::cout << GREEN << std::endl << "----- Inherited Member function calls -----" << RESET << std::endl;
	std::cout << "Methods from FragTrap" << std::endl;
	diamond.highFivesGuys();
	std::cout << "Methods from ScavTrap" << std::endl;
	diamond.guardGate();
	diamond.attack("enemy");
	std::cout << "Methods from ClapTrap" << std::endl;
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	std::cout << "Hit points: "<< diamond.getHitPoints() << std::endl;

	std::cout << GREEN << std::endl << "----- New Member function calls -----" << RESET << std::endl;
	diamond.whoAmI();
	
	std::cout << GREEN << std::endl << "----- Destructor calls -----" << RESET << std::endl;
	return (0);
}
