/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:00:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 20:59:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::string scav_name = "Scavy";
	std::string scav_copy = "ScavyCopy";
	
	std::cout << "----- Constructor calls -----" << std::endl;
	ScavTrap scavy(scav_name);

	std::cout << std::endl << "----- Inherited Member function calls -----" << std::endl;
	scavy.takeDamage(10);
	scavy.beRepaired(10);
	
	std::cout << std::endl << "----- Modified Member function calls -----" << std::endl;
	scavy.attack("some other enemy");
	scavy.guardGate();

	std::cout << std::endl << "----- Operator overloads -----" << std::endl;
	ScavTrap scavy2 = scavy;
	scavy2.attack("another enemy");
	
	std::cout << std::endl << "----- Copy constructor -----" << std::endl;
	ScavTrap scavy3(scavy2);
	scavy3.attack("one more enemy");

	std::cout << std::endl << "----- Polymorphism -----" << std::endl;
	ClapTrap *scavy4 = new ScavTrap(scav_copy);
	scavy4->attack("yet another enemy");
	
	std::cout << std::endl << "----- Destructor calls -----" << std::endl;
	delete scavy4;
	return (0);	
}
