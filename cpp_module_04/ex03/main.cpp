/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:59:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:28:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

int main(void) {
	std::cout << YELLOW << "-------- Create Materia Source --------" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << YELLOW << "-------- Create Character --------" << RESET << std::endl;
	ICharacter* me = new Character("me");

	std::cout << YELLOW << "-------- Assign Materia --------" << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << YELLOW << "-------- Create Character Bob --------" << RESET << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << YELLOW << "-------- Use Materia on Bob --------" << RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << YELLOW << "-------- Delete characters --------" << RESET << std::endl;
	std::cout << YELLOW << "-------- Bob has no materia --------" << RESET << std::endl;
	delete bob;
	std::cout << YELLOW << "-------- I have two materia --------" << RESET << std::endl;
	delete me;
	std::cout << YELLOW << "-------- Delete Materia Source --------" << RESET << std::endl;
	delete src;

	return (0);
}
