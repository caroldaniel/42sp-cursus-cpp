/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:00:23 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 15:16:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << std::endl << YELLOW << "------ Creating a bureaucrat with grade 1 ------" << RESET << std::endl;
	try {
		Bureaucrat b1("John", 1);
		std::cout << b1;
		std::cout << "Decrementing grade..." << std::endl;
		b1.decrementGrade();
		std::cout << b1;
		std::cout << "Incrementing grade..." << std::endl;
		b1.incrementGrade();
		std::cout << b1;
		std::cout << "Incrementing grade again..." << std::endl;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a bureaucrat with grade 150 ------" << RESET << std::endl;
	try {
		Bureaucrat b2("John", 150);
		std::cout << b2;
		std::cout << "Incrementing grade..." << std::endl;
		b2.incrementGrade();
		std::cout << b2;
		std::cout << "Decrementing grade..." << std::endl;
		b2.decrementGrade();
		std::cout << b2;
		std::cout << "Decrementing grade again..." << std::endl;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a bureaucrat with grade 0 ------" << RESET << std::endl;
	try {
		Bureaucrat b3("John", 0);
		std::cout << b3;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a bureaucrat with grade 151 ------" << RESET << std::endl;
	try {
		Bureaucrat b4("John", 151);
		std::cout << b4;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
