/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:48:54 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/30 19:01:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Zombie {
	private:
		std::string _name;
	public:
		// Constructors and destructors
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		// Setters
		void setName(std::string name);
		// Getters
		std::string getName(void);
		// Member functions
		void announce(void);
};

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif