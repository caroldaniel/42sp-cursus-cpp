/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:37:44 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 15:15:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
   std::cout << std::endl << YELLOW << "------ RobotomyCreationForm : #1 ------" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << YELLOW << "------ PresidentialPardonForm : #2 ------" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *ppf << std::endl;
        delete ppf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << YELLOW << "------ ShrubberyCreationForm : #3 ------" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *scf << std::endl;
        delete scf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << YELLOW << "------ AnyForm : Error ------" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("any form", "Bender");
        std::cout << *scf << std::endl;
        delete scf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}