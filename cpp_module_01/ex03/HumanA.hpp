/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:06:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:20:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	//parameter constructor
	HumanA(const std::string initialName, Weapon& initialWeapon);
	//destructor
	~HumanA();

	//attack method
	void	attack(void) const;
};

#endif