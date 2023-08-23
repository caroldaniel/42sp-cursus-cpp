/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:07:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:32:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	
public:
	// Default constructor
	ClapTrap(void);
	// Constructor
	ClapTrap(std::string &name);
	// Copy constructor
	ClapTrap(const ClapTrap &source);
	// Destructor
	virtual		~ClapTrap(void);
	// Operator overloads
	ClapTrap	&operator=(const ClapTrap &other);
	// Getters
	std::string	getName(void);
	int			getHitPoints(void);
	int			getEnergyPoints(void);
	int			getAttackDamage(void);
	// Setters
	void		setName(std::string name);
	void		setHitPoints(int hitPoints);
	void		setEnergyPoints(int energyPoints);
	void		setAttackDamage(int attackDamage);
	// Member functions
	virtual void	attack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif