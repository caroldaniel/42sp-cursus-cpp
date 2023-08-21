/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:00:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/20 22:06:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string hero_name = "Hero";
	std::string villain_name = "Villain";
	ClapTrap hero(hero_name);
	ClapTrap villain(villain_name);

	std::cout << hero.getName() << " is so smart, first thing they do is to repair themselves." << std::endl;
	hero.beRepaired(10);
	std::cout << villain.getName() << " just wants to attack." << std::endl;
	villain.attack(hero.getName());
	std::cout << hero.getName() << " now attacks" << std::endl;
	hero.attack(villain.getName());
	std::cout << "None of them have any attack damage points! This will be a never ending fight!" << std::endl;
	villain.takeDamage(hero.getAttackDamage());
	std::cout << "In anger, " << villain.getName() << " attacked 9 times in a row!" << std::endl;
	for (int i = 0; i < 9; i++)
		villain.attack(hero.getName());
	std::cout << hero.getName() << " didn't feel even an itch." << std::endl;
	std::cout << villain.getName() << " is so tired, they can't attack anymore." << std::endl;
	villain.attack(hero.getName());
	std::cout << hero.getName() << " won!" << std::endl;
	return (0);	
}
