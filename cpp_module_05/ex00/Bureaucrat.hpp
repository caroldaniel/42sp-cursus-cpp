/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:20:30 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 20:11:00 by cado-car         ###   ########.fr       */
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
	static const int	_max_grade = 1;
	static const int	_min_grade = 150;
	std::string const	_name;
	int					_grade;
public:
	// Constructors and destructor
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &source);
	~Bureaucrat(void);

	// Operator overloads
	Bureaucrat			&operator=(const Bureaucrat &other);
	friend std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

	// Member functions
	std::string const	&getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif