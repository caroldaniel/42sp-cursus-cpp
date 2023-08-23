/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:17:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 12:16:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors and destructor
Brain::Brain(void) {
	std::stringstream ss;
	for (int i = 0; i < 100; i++) {
		ss << i;
		_ideas[i] = "Idea #" + ss.str();
	}
	std::cout << "Brain constructed!" << std::endl;
	return ;
}
Brain::Brain(const Brain &source) {
	*this = source;
	std::cout << "Brain copy constructed!" << std::endl;
	return ;
}
Brain::~Brain(void) {
	std::cout << "Brain destructed!" << std::endl;
	return ;
}

// Operator overloads
Brain	&Brain::operator=(const Brain &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

// Member functions
std::string	*Brain::getIdeas(void) {
	return (_ideas);
}