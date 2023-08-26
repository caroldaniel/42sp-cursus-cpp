/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:31:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 15:23:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source) {
	if (this == &source)
		return (*this);
	_grade = source._grade;
	return (*this);
}

// Getters
std::string	Bureaucrat::getName(void) const {
	return (_name);
}
int			Bureaucrat::getGrade(void) const {
	return (_grade);
}

// Member functions
void		Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}
void		Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

// Exception classes
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Grade too high!" RESET);
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Grade too low!" RESET);
}

// Stream operator overload
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << YELLOW << bureaucrat.getName() << RESET << ", bureaucrat grade " << GREEN << bureaucrat.getGrade() << RESET << "." << std::endl;
	return (os);
}