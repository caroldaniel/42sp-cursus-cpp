/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:17:52 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/28 22:15:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void) {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Welcome to the Phonebook!" << std::endl << std::endl;
	while (1) {
		std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "\nPlease enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			std::cout << GREEN << "\nBye!" << RESET << std::endl;
			break ;
		}
		else if (input == "ADD") {
			phonebook.addContact();
		}
		else if (input == "SEARCH") {
			phonebook.searchContact();
		}
		else {
			std::cout << RED << "\nInvalid command. Please try again.\n" << RESET << std::endl;
		}
	}
	return (0);
}