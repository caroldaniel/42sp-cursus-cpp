/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:54:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 15:05:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

static void	test_schrubbery(void);
static void	test_robotomy(void);
static void	test_presidential(void);

int main(void) {
	test_schrubbery();
	test_robotomy();
	test_presidential();
	return (0);
}

static void	test_schrubbery(void) {
	std::cout << std::endl << YELLOW << "------ ShrubberyCreationForm : #1 ------" << RESET << std::endl;
	try {
		ShrubberyCreationForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ ShrubberyCreationForm : #2 ------" << RESET << std::endl;
		try {
		ShrubberyCreationForm form("Betty");
		Bureaucrat bureaucrat("Nick", 140);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ ShrubberyCreationForm : #3 ------" << RESET << std::endl;
	try {
		ShrubberyCreationForm form("Carla");
		Bureaucrat bureaucrat("Evan", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	test_robotomy(void) {
	std::cout << std::endl << YELLOW << "------ RobotomyCreationForm : #1 ------" << RESET << std::endl;
	try {
		RobotomyRequestForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ RobotomyCreationForm : #2 ------" << RESET << std::endl;
		try {
		RobotomyRequestForm form("Betty");
		Bureaucrat bureaucrat("Nick", 60);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ RobotomyCreationForm : #3 ------" << RESET << std::endl;
	try {
		RobotomyRequestForm form("Carla");
		Bureaucrat bureaucrat("Evan", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	test_presidential(void) {
	std::cout << std::endl << YELLOW << "------ PresidentialPardonForm : #1 ------" << RESET << std::endl;
	try {
		PresidentialPardonForm form("Alice");
		Bureaucrat bureaucrat("John", 1);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ PresidentialPardonForm : #2 ------" << RESET << std::endl;
		try {
		PresidentialPardonForm form("Betty");
		Bureaucrat bureaucrat("Nick", 15);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ PresidentialPardonForm : #3 ------" << RESET << std::endl;
	try {
		PresidentialPardonForm form("Carla");
		Bureaucrat bureaucrat("Evan", 150);
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
