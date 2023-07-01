/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:06:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:21:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
private:
	std::string		_name;
	const Weapon	*_weapon;

public:
	//parameter constructor
	HumanB(const std::string initialName);
	//destructor
	~HumanB();

	//attack method
	void	setWeapon(const Weapon& newWeapon);
	void	attack(void) const;
};

#endif