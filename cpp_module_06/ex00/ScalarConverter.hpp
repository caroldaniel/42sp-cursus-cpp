/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:07:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 20:10:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string.h>
# include <limits>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"

// Enumerators
enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

// Global variables
const std::string _pseudo_literals[] = {"nan", "inf"};

// Class definition
class ScalarConverter {
private:
    // Private constructor and destructor - Static class (non-instantiable)
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &source);
    ~ScalarConverter(void);
    // Operator overload
    ScalarConverter &operator=(const ScalarConverter &source);
    // Get type
    static int _getType(const std::string &literal);
    // Member functions for checking
    static bool _isChar(const std::string &literal);
    static bool _isInt(const std::string &literal);
    static bool _isFloat(const std::string &literal);
    static bool _isDouble(const std::string &literal);
    // Member functions for converting
    static char _toChar(const std::string &literal);
    static int _toInt(const std::string &literal);
    static float _toFloat(const std::string &literal);
    static double _toDouble(const std::string &literal);
public:
    static void convert(const std::string &literal);
    // Exceptions
    class InvalidLiteralException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class NonDisplayableException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif