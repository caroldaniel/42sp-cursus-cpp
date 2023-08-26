/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:07:27 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 15:26:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

class Bureaucrat;

class Form
{
private:
	static int const	_max_grade = 1;
	static int const	_min_grade = 150;
	std::string const	_name;
	bool				_signed;
	int const			_grade_to_sign;
	int const			_grade_to_execute;
public:
	// Constructors and destructor
	Form(void);
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &source);
	~Form(void);
	// Assignment Operator overload
	Form	&operator=(const Form &other);
	// Getters
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;
	// Member functions
	void		beSigned(Bureaucrat &bureaucrat);	
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
};

// Overload << operator for output
std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif