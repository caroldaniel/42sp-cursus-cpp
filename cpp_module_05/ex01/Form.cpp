/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:09:33 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 15:27:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
Form::Form(void) : _name("default"), _grade_to_sign(150), _grade_to_execute(150) {
	return ;
}
Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < _max_grade || grade_to_execute < _max_grade)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > _min_grade || grade_to_execute > _min_grade)
		throw Form::GradeTooLowException();
	else
		_signed = false;
	return ;
}
Form::Form(const Form &source) : _name(source._name), _grade_to_sign(source._grade_to_sign), _grade_to_execute(source._grade_to_execute) {
	*this = source;
	return ;
}
Form::~Form(void) {
	return ;
}

// Operator overloads
Form	&Form::operator=(const Form &other) {
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}
std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << GREEN << form.getName() << RESET << ", form grade to sign " << YELLOW << form.getGradeToSign() << RESET << ", form grade to execute " << YELLOW << form.getGradeToExecute() << RESET << "." << std::endl;
	return (out);
}

// Getters
std::string	Form::getName(void) const {
	return (_name);
}
bool		Form::getSigned(void) const {
	return (_signed);
}
int			Form::getGradeToSign(void) const {
	return (_grade_to_sign);
}
int			Form::getGradeToExecute(void) const {
	return (_grade_to_execute);
}

// Member functions
void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
	return ;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
	return (RED "Grade too high!" RESET);
}
const char *Form::GradeTooLowException::what() const throw() {
	return (RED "Grade too low!" RESET);
}
