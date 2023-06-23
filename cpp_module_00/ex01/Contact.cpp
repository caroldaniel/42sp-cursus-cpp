/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:36:12 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/22 23:51:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void setInput(std::string attribute, const std::string prompt, const std::string errorMessage, void (Contact::*setter)(const std::string)) {
	int attempts = 0;

	while (attempts < 3) {
		std::cout << prompt;
		std::getline(std::cin, attribute);
		
		try {
			(Contact().*setter)(attribute);
			break ;
		}
		catch (std::invalid_argument& e) {
			std::cout << errorMessage << std::endl;
			attempts++;
		}
	}
	if (attempts == 3) {
		throw std::runtime_error("Failed to set the attribute after three attempts.");
	}
}

// Constructors and destructors
Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

// Setters
void	Contact::setFirstName(std::string firstName) {
	std::string::iterator it;
	bool isAlpha = true;

	if (firstName.empty()) {
        throw std::invalid_argument("Empty first name.");
    }	
	for (it = firstName.begin(); it < firstName.end(); ++it) {
		if (!std::isalpha(*it)) {
			isAlpha = false;
			break ;
		}
	}
	if (!isAlpha) {
		throw std::invalid_argument("Invalid first name.");
	}
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	std::string::iterator it;
	bool isAlpha = true;

	if (lastName.empty()) {
		throw std::invalid_argument("Empty last name.");
	}	
	for (it = lastName.begin(); it < lastName.end(); ++it) {
		if (!std::isalpha(*it)) {
			isAlpha = false;
			break ;
		}
	}
	if (!isAlpha) {
		throw std::invalid_argument("Invalid last name.");
	}
	_lastName = lastName;
};

void	Contact::setNickname(std::string nickname) {
	std::regex pattern("^[\\w.-_]+$");

	if (nickname.empty()) {
		throw std::invalid_argument("Empty nickname.");
	}	
	if (!std::regex_match(nickname, pattern)) {
		throw std::invalid_argument("Invalid nickname.");
	}
	_nickname = nickname;
};

void	Contact::setPhoneNumber(std::string phoneNumber) {
	std::regex pattern("^\\d{11}$");

	if (phoneNumber.empty()) {
		throw std::invalid_argument("Empty phone number.");
	}	
	if (!std::regex_match(phoneNumber, pattern)) {
		throw std::invalid_argument("Invalid phone number.");
	}
	_phoneNumber = phoneNumber;
};

void	Contact::setDarkestSecret(std::string darkestSecret) {
	if (darkestSecret.empty()) {
		throw std::invalid_argument("Empty darkest secret.");
	}
	_darkestSecret = darkestSecret;
};

// Getters

std::string	Contact::getFirstName(void) {
	return (_firstName);
};

std::string	Contact::getLastName(void) {
	return (_lastName);
};

std::string	Contact::getNickname(void) {
	return (_nickname);
};

std::string	Contact::getPhoneNumber(void) {
	return (_phoneNumber);
};

std::string	Contact::getDarkestSecret(void) {
	return (_darkestSecret);
};

// Methods
void	Contact::setContact(void) {
	try {
		setInput(_firstName, "Enter first name: ", "Invalid input. Please try again.", &Contact::setFirstName);
		setInput(_lastName, "Enter last name: ", "Invalid input. Please try again.", &Contact::setLastName);
		setInput(_nickname, "Enter nickname: ", "Invalid input. Please try again.", &Contact::setNickname);
		setInput(_phoneNumber, "Enter phone number: ", "Invalid input. Please try again.", &Contact::setPhoneNumber);
		setInput(_darkestSecret, "Enter darkest secret: ", "Invalid input. Please try again.", &Contact::setDarkestSecret);
    } 
	catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
};
