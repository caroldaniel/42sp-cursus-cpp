/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:55:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 23:12:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "----- Constructor calls -----" << std::endl;
	DiamondTrap diamond("Diamond");
	
	std::cout << std::endl << "----- Get attributes -----" << std::endl;
	std::cout << "Name: " << diamond.getName() << std::endl;
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;
	
	std::cout << std::endl << "----- Inherited Member function calls -----" << std::endl;
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	diamond.attack("enemy");

	std::cout << std::endl << "----- Modified Member function calls -----" << std::endl;
	diamond.highFivesGuys();

	std::cout << "----- Member function calls -----" << std::endl;
	diamond.whoAmI();
	
	std::cout << "----- Destructor calls -----" << std::endl;
	return (0);
}