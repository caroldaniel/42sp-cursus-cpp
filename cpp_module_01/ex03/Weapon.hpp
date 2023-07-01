/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:51:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/01 13:20:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
private:
	std::string _type;

public:
	//default constructor
	Weapon();
	//parameter constructor
	Weapon(const std::string initialType);
	//destructor
	~Weapon();
	
	//setters
	void				setType(const std::string newType);

	//getters
	const std::string&	getType(void) const;
};

#endif