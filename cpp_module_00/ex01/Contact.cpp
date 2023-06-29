/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:36:12 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/28 21:36:11 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	if (nickname.empty()) {
		throw std::invalid_argument("Empty nickname.");
	}
	for (std::size_t i = 0; i < nickname.size(); ++i) {
        char ch = nickname[i];
        if (!std::isalnum(ch) && ch != '-' && ch != '_' && ch != '.') {
			throw std::invalid_argument("Invalid nickname.");
		}
    }	
	_nickname = nickname;
};

void	Contact::setPhoneNumber(std::string phoneNumber) {
	if (phoneNumber.empty()) {
		throw std::invalid_argument("Empty phone number.");
	}	
	for (std::size_t i = 0; i < phoneNumber.size(); ++i) {
        char digit = phoneNumber[i];
        if (!std::isdigit(digit)) {
            throw std::invalid_argument("Invalid phone number.");
        }
	_phoneNumber = phoneNumber;
	}
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
		setInput("\tEnter first name: ", "Invalid input. Please try again.", &Contact::setFirstName);
		setInput("\tEnter last name: ", "Invalid input. Please try again.", &Contact::setLastName);
		setInput("\tEnter nickname: ", "Invalid input. Please try again.", &Contact::setNickname);
		setInput("\tEnter phone number: ", "Invalid input. Please try again.", &Contact::setPhoneNumber);
		setInput("\tEnter darkest secret: ", "Invalid input. Please try again.", &Contact::setDarkestSecret);
		std::cout << GREEN << "Contact added successfully!\n" << RESET << std::endl;
    } 
	catch (const std::runtime_error& e) {
		clearInput(_firstName);
		clearInput(_lastName);
		clearInput(_nickname);
		clearInput(_phoneNumber);
		clearInput(_darkestSecret);
		throw std::runtime_error(e.what());
    }
	return ;
}

void 	Contact::setInput(const std::string& prompt, const std::string& errorMessage, void (Contact::*setter)(const std::string))
{
	std::string value;
	bool isValid;

	isValid = false;
	for (int i = 0; i < 3 && !isValid; i++)
	{
		std::cout << GREEN << prompt << RESET;
		std::getline(std::cin, value);
		try
		{
			(this->*setter)(value);
			isValid = true;
		}
		catch (const std::exception& e)
		{
			std::cout << YELLOW << errorMessage << RESET << std::endl;
		}
	}
	if (!isValid)
		throw std::runtime_error("Failed to set the attribute after three attempts.");
	return ;
}

void	Contact::clearInput(std::string& input) {
	input.clear();
}

void	Contact::printContact(void) {
	std::cout <<std::endl;
	std::cout << "First name: " << this->getFirstName() << std::endl;
	std::cout << "Last name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
	std::cout <<std::endl;
}
