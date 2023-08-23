/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:14:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:09:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors and destructor
Character::Character(void) {
	_name = "Default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Character constructed!" << std::endl;
	return ;
}
Character::Character(std::string const &name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " constructed!" << std::endl;
	return ;
}
Character::Character(const Character &source) {
	// Deep copy
	_name = source._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = source._inventory[i]->clone();
	std::cout << "Character " << _name << " copy constructed!" << std::endl;
	return ;
}
Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "Character " << _name << " destructed!" << std::endl;
	return ;
	
}

// Operator overloads
Character	&Character::operator=(const Character &other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

// Member functions
std::string const	&Character::getName(void) const {
	return (this->_name);
}
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
	return ;
}
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
	return ;
}