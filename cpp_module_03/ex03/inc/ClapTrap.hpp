/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:07:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 13:33:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

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