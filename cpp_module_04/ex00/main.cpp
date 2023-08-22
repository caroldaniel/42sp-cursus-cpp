/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:37:30 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:57:07 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int	main(void) {
	std::cout << std::endl << YELLOW << "Testing Animal class:" << RESET << std::endl << std::endl;
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();

	std::cout << std::endl << YELLOW << "Testing WrongAnimal class:" << RESET << std::endl << std::endl;
	const	WrongAnimal* gama = new WrongAnimal();
	const	WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will output the wrong cat sound!
	gama->makeSound();


	return (0);
}
