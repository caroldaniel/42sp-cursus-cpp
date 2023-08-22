/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:00:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:40:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::string scav_name = "Fraggy";
	std::string scav_copy = "FraggyCopy";
	
	std::cout << std::endl << GREEN << "----- Constructor calls -----" << RESET << std::endl;
	FragTrap scavy(scav_name);

	std::cout << std::endl << GREEN << "----- Inherited Member function calls -----" << RESET << std::endl;
	scavy.takeDamage(10);
	scavy.beRepaired(10);
	
	std::cout << std::endl << GREEN << "----- Modified Member function calls -----" << RESET << std::endl;
	scavy.attack("some other enemy");
	scavy.highFivesGuys();

	std::cout << std::endl << GREEN << "----- Operator overloads -----" << RESET << std::endl;
	FragTrap scavy2 = scavy;
	scavy2.attack("another enemy");
	
	std::cout << std::endl << GREEN << "----- Copy constructor -----" << RESET << std::endl;
	FragTrap scavy3(scavy2);
	scavy3.attack("one more enemy");

	std::cout << std::endl << GREEN << "----- Polymorphism -----" << RESET << std::endl;
	ClapTrap *scavy4 = new FragTrap(scav_copy);
	scavy4->attack("yet another enemy");
	
	std::cout << std::endl << GREEN << "----- Destructor calls -----" << RESET << std::endl;
	delete scavy4;
	return (0);	
}
