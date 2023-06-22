/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:35:41 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/22 01:43:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void setInput(std::string& attribute, const std::string& prompt, const std::string& errorMessage, void (Contact::*setter)(const std::string&)) {
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
	if (attempts >= 3) {
		throw std::runtime_error("Failed to set the attribute after three attempts.");
	}
}
