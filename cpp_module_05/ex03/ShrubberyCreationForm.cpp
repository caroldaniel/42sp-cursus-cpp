/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:51:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 19:03:39 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default", 1, 1), _target("default") {
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source), _target(source._target) {
	*this = source;
	return ;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

// Operator overloads
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source) {
	if (this == &source)
		return (*this);
	_target = source._target;
	return (*this);
}

// Member functions
std::string ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}
void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file << "      ||      " << std::endl;
	file << "    \\****/    " << std::endl;
	file << "     \\**/     " << std::endl;
	file << "      \\/      " << std::endl;
	file.close();
}

// Exception classes
const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return ("Error: could not open file.");
}
