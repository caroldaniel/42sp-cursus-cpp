/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:14:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	std::cout << std::endl << "----- Constructor calls -----" << std::endl;
	DiamondTrap diamond("Diamond");
	
	std::cout << std::endl << "----- Get attributes -----" << std::endl;
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "ClapTrapName: " << diamond.getClapName() << std::endl;
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;
	
	std::cout << std::endl << "----- Inherited Member function calls -----" << std::endl;
	std::cout << "Methods from FragTrap" << std::endl;
	diamond.highFivesGuys();
	std::cout << "Methods from ScavTrap" << std::endl;
	diamond.guardGate();
	diamond.attack("enemy");
	std::cout << "Methods from ClapTrap" << std::endl;
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	std::cout << "Hit points: "<< diamond.getHitPoints() << std::endl;

	std::cout << std::endl << "----- New Member function calls -----" << std::endl;
	diamond.whoAmI();
	
	std::cout << std::endl << "----- Destructor calls -----" << std::endl;
	return (0);
}
