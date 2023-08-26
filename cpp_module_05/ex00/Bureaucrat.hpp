/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:20:30 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 15:06:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// Libraries
# include <iostream>
# include <string>
# include <exception>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

// Class
class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	// Default constructor
	Bureaucrat(void);
	// Parameter constructor
	Bureaucrat(std::string name, int grade);
	// Copy constructor
	Bureaucrat(const Bureaucrat &source);
	// Destructor
	~Bureaucrat(void);
	// Assignment Operator overload
	Bureaucrat	&operator=(const Bureaucrat &source);
	// Getters
	std::string	getName(void) const;
	int			getGrade(void) const;
	// Member functions
	void		incrementGrade(void);
	void		decrementGrade(void);
	// Exception classes
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

// Overload << operator for output
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif