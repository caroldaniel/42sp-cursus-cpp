/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:14:52 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/28 16:47:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

enum FormType {
    ROBOTOMY_REQUEST,
    PRESIDENTIAL_PARDON,
    SHRUBBERY_CREATION
};

class Intern
{
private:
    std::string   _form_types[3];
public:
    Intern();
    ~Intern();
    // Member functions
    AForm* makeForm(std::string name, std::string target);
    // Exceptions
    class FormNotFoundException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif