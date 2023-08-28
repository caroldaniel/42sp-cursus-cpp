/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:09:22 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 19:10:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
	return ;
}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < _maxGrade || gradeToExecute < _maxGrade)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > _minGrade || gradeToExecute > _minGrade)
		throw AForm::GradeTooLowException();
	return ;
}
AForm::AForm(const AForm &source) : _name(source._name), _signed(source._signed), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {
	*this = source;
	return ;
}
AForm::~AForm(void) {
	return ;
}

// Operator overloads
AForm	&AForm::operator=(const AForm &source) {
	if (this == &source)
		return (*this);
	_signed = source._signed;
	return (*this);
}

// Member functions
std::string AForm::getName(void) const {
	return (_name);
}
bool		AForm::getSigned(void) const {
	return (_signed);
}
int			AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}
int			AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

// Sign form
void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
	return ;
}

// Exception classes
const char *AForm::GradeTooHighException::what() const throw() {
	return (RED "Grade too high!" RESET);
}
const char *AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade too low!" RESET);
}
const char *AForm::FormNotSignedException::what() const throw() {
	return (RED "Form not signed!" RESET);
}

// Overload << operator for output
std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << " is ";
	if (form.getSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (os);
}
