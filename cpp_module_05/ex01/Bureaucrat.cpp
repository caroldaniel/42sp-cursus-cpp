/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:31:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 22:08:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and destructor
Bureaucrat::Bureaucrat(void) {
	return ;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}
Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name) {
	*this = source;
	return ;
}
Bureaucrat::~Bureaucrat(void) {
	return ;
}

// Operator overloads
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << GREEN << bureaucrat.getName() << RESET << ", bureaucrat grade " << YELLOW << bureaucrat.getGrade() << RESET << "." << std::endl;
	return (out);
}

// Member functions
std::string const	&Bureaucrat::getName(void) const {
	return (_name);
}
int					Bureaucrat::getGrade(void) const {
	return (_grade);
}
void				Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
	return ;
}
void				Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
	return ;
}

// Form signing
void				Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << RESET << " signs " << GREEN << form.getName() << RESET << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << _name << RESET << " couldn’t sign " << RED << form.getName() << RESET << " because " << RED << e.what() << RESET << std::endl;
	}
	return ;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Grade too high!" RESET);
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Grade too low!" RESET);
}
