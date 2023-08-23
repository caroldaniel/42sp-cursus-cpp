/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:57:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:04:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// DiamondTrap class
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
	public:
		// Default constructor
		DiamondTrap(void);
		// Class constructor
		DiamondTrap(std::string name);
		// Copy constructor
		DiamondTrap(const DiamondTrap& other);
		// Destructor
		~DiamondTrap(void);
		// Operator
		DiamondTrap& operator=(const DiamondTrap& other);
		// Getters
		std::string	getName(void);
		std::string	getClapName(void);
		int			getHitPoints(void);
		int			getEnergyPoints(void);
		int			getAttackDamage(void);
		// Member functions
		void	whoAmI(void);
};

#endif