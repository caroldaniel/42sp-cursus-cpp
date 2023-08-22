/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:06:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 15:39:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// FragTrap class
class FragTrap : public ClapTrap
{
	public:
		// Default constructor
		FragTrap(void);
		// Class constructor
		FragTrap(std::string name);
		// Copy constructor
		FragTrap(const FragTrap& other);
		// Destructor
		~FragTrap(void);
		// Operator overloads
		FragTrap	&operator=(const FragTrap &other);
		// Member functions
		void	highFivesGuys(void);
};

#endif