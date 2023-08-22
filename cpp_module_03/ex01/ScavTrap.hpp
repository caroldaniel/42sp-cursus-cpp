/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:40:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 20:51:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// Default constructor
	ScavTrap(void);
	// Constructor
	ScavTrap(std::string &name);
	// Copy constructor
	ScavTrap(const ScavTrap &source);
	// Destructor
	~ScavTrap(void);
	// Member functions
	void	attack(std::string const &target);
	void	guardGate(void);
};

#endif