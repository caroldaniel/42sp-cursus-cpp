/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:10:54 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 19:22:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default", 1, 1), _target("default") {
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), _target(source._target) {
	*this = source;
	return ;
}
RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

// Operator overloads
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
	if (this == &source)
		return (*this);
	_target = source._target;
	return (*this);
}

// Member functions
std::string RobotomyRequestForm::getTarget(void) const {
	return (_target);
}
void		RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}
