/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:45:15 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 22:15:33 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << "Creating a Bureaucrat with grade 1..." << std::endl;
	Bureaucrat b1("Bureaucrat 1", 1);
	std::cout << b1 << std::endl;
	std::cout << "Creating a Bureaucrat with grade 150..." << std::endl;
	Bureaucrat b2("Bureaucrat 2", 150);
	std::cout << b2 << std::endl;
	std::cout << "Creating a Form with grade to sign 1 and grade to execute 1..." << std::endl;
	Form f1("Form 1", 1, 1);
	std::cout << f1 << std::endl;
	std::cout << "Creating a Form with grade to sign 150 and grade to execute 150..." << std::endl;
	Form f2("Form 2", 150, 150);
	std::cout << f2 << std::endl;
	std::cout << "Creating a Form with grade to sign 1 and grade to execute 150..." << std::endl;
	Form f3("Form 3", 1, 150);
	std::cout << f3 << std::endl;
	std::cout << "Creating a Form with grade to sign 150 and grade to execute 1..." << std::endl;
	Form f4("Form 4", 150, 1);
	std::cout << f4 << std::endl;
	std::cout << "Creating a Form with grade to sign 0 and grade to execute 1..." << std::endl;
	try {
		Form f5("Form 5", 0, 1);
		std::cout << f5 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a Form with grade to sign 1 and grade to execute 0..." << std::endl;
	try {
		Form f6("Form 6", 1, 0);
		std::cout << f6 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a Form with grade to sign 151 and grade to execute 1..." << std::endl;
	try {
		Form f7("Form 7", 151, 1);
		std::cout << f7 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a Form with grade to sign 1 and grade to execute 151..." << std::endl;
	try {
		Form f8("Form 8", 1, 151);
		std::cout << f8 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// Sign a form
	std::cout << "Signing a form with a bureaucrat with grade 1..." << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "Signing a form with a bureaucrat with grade 150..." << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << "Signing a form with a bureaucrat with grade 1..." << std::endl;
	b1.signForm(f3);
	std::cout << f3 << std::endl;
	std::cout << "Signing a form with a bureaucrat with grade 150..." << std::endl;
	b2.signForm(f4);
	std::cout << f4 << std::endl;
	// Try to sign a form
	std::cout << "Trying to sign a form with a bureaucrat with grade 150..." << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "Trying to sign a form with a bureaucrat with grade 1..." << std::endl;
	b1.signForm(f2);
	std::cout << f2 << std::endl;
	return (0);	
}