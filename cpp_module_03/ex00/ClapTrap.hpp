/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:07:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/20 21:56:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	
public:
	// Constructors and destructor
	ClapTrap(void);
	ClapTrap(std::string &name);
	~ClapTrap(void);
	// Operator overloads
	ClapTrap	&operator=(const ClapTrap &other);
	// Getters
	std::string	getName(void);
	int			getHitPoints(void);
	int			getEnergyPoints(void);
	int			getAttackDamage(void);
	// Member functions
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif