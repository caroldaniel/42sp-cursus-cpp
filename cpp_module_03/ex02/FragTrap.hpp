/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:06:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/21 21:13:33 by cado-car         ###   ########.fr       */
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
		// Member functions
		void	highFivesGuys(void);
};

#endif