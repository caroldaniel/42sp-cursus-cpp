/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:07:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/26 18:55:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
private:
	static int const	_maxGrade = 1;
	static int const	_minGrade = 150;
	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExecute;
public:
	// Constructors and destructor
	AForm(void);
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &source);
	virtual ~AForm(void);

	// Operator overloads
	AForm	&operator=(const AForm &other);

	// Member functions
	std::string getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;
	void		beSigned(Bureaucrat &bureaucrat);
	// Pure virtual functions
	virtual void		execute(Bureaucrat const &executor) const = 0;
	// Exception classes
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

// Insertion operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif