/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:04:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/26 21:23:06 by cado-car         ###   ########.fr       */
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
	try {
		_contacts[_index % _MAX_CONTACTS].setContact();
		if (_contactCount < _MAX_CONTACTS)
			_contactCount++;
		else
			std::cout << YELLOW << "Phonebook is full. Oldest register have been replaced." << RESET << std::endl;
		_index++;
	}
	catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return ;
}

void	Phonebook::searchContact(void) {
	std::stringstream	ss;
	std::string 		input;
	
	print_line("Index", "First Name", "Last Name", "Nickname");
	print_line("----------", "----------", "----------", "----------");
	for (int i = 0; i < _contactCount; i++) {
		ss.str("");
		ss << i;
		print_line(ss.str(), _contacts[i].getFirstName(), _contacts[i].getLastName(), _contacts[i].getNickname());
	}
	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && input[0] - '0' < _contactCount)
		_contacts[input[0] - '0'].printContact();
	else
		std::cout << RED << "\nError: Invalid index.\n" << RESET << std::endl;
	return ;
}

void	print_line(std::string index, std::string first_name, std::string last_name, std::string nickname) {
	
	std::cout << "|";
	print_field(index);
	std::cout << "|";
	print_field(first_name);
	std::cout << "|";
	print_field(last_name);
	std::cout << "|";
	print_field(nickname);
	std::cout << "|" << std::endl;
	return ;
}

void	print_field(std::string field) {
    std::string	truncatedText;
	int 		padding;
	
    if (field.length() > 10) {
        truncatedText = field.substr(0, 9) + ".";
    } 
	else {
        truncatedText = field;
    }
    padding = 10 - truncatedText.length();
    for (int i = 0; i < padding; ++i) {
        std::cout << " ";
    }
    std::cout << truncatedText;
	return ;
}
