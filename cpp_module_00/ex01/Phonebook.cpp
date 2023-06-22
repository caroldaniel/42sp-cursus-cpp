/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:04:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/22 01:21:24 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// Constructors and destructors
Phonebook::Phonebook(void) {
	_index = 0;
	_contactCount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

// Methods
void	Phonebook::addContact(void) {
	if (_contactCount < _MAX_CONTACTS) {
		_contacts[_index].setContact();
		_index++;
		_contactCount++;
	}
	else {
		std::cout << "Phonebook is full. Cannot add more contacts." << std::endl;
	}
}