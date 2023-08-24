/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:07:27 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 22:07:57 by cado-car         ###   ########.fr       */
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

	// Operator overloads
	Form	&operator=(const Form &other);
	friend std::ostream	&operator<<(std::ostream &out, const Form &form);

	// Member functions
	std::string const	&getName(void) const;
	bool				getSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;
	void				beSigned(const Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif