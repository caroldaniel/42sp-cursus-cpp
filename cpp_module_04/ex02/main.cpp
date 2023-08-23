/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:37:30 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:17:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int	main(void) {
	std::cout << std::endl << YELLOW << "-------- Create Dog --------" << RESET << std::endl << std::endl;
	const Dog *dog = new Dog();

	std::cout << std::endl << YELLOW << "-------- Create Cat --------" << RESET << std::endl << std::endl;
	const Cat *cat = new Cat();
	
	std::cout << std::endl << YELLOW << "-------- Delete Dog --------" << RESET << std::endl << std::endl;
	delete dog; //should not create a leak
	
	std::cout << std::endl << YELLOW << "-------- Delete Cat --------" << RESET << std::endl << std::endl;
	delete cat; //should not create a leak
	
	return (0);
}
