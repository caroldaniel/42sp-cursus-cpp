/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:33 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 19:28:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor and destructors
ScalarConverter::ScalarConverter(void) {
    return ;
}
ScalarConverter::ScalarConverter(const ScalarConverter &source) {
    *this = source;
    return ;
}
ScalarConverter::~ScalarConverter(void) {
    return ;
}

// Operator Overloads
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
	if (this == &source)
		return (*this);
    *this = source;
	return (*this);
}

// Convert
void ScalarConverter::convert(const std::string &literal) {
    try {
        int type = _getType(literal);
        switch (type)
        {
        case CHAR:
            std::cout << "char: " << _toChar(literal) << std::endl;
            break;
        case INT:
            std::cout << "int: " << _toInt(literal) << std::endl;
            break;
        case FLOAT:
            std::cout << "float: " << _toFloat(literal) << std::endl;
            break;
        case DOUBLE:
            std::cout << "double: " << _toDouble(literal) << std::endl;
            break;
        default:
            throw InvalidLiteralException();
            break;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return ;    
}

// Get type
int ScalarConverter::_getType(const std::string &literal) {
    if (_isChar(literal))
        return (CHAR);
    if (_isInt(literal))
        return (INT);
    if (_isFloat(literal))
        return (FLOAT);
    if (_isDouble(literal))
        return (DOUBLE);
    throw InvalidLiteralException();
}

// Member functions for checking
bool ScalarConverter::_isChar(const std::string &literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}
bool ScalarConverter::_isInt(const std::string &literal) {
    size_t  len = literal.length();

    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            continue ;
        if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}
bool ScalarConverter::_isFloat(const std::string &literal) {
    size_t  len = literal.length();
    size_t  i = 0;
    bool    dot = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inff" || literal.substr(i, len) == "nanf")
        return (true);
    if (literal[len - 1] != 'f')
        return (false);
    for (; i < len - 2; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}
bool ScalarConverter::_isDouble(const std::string &literal) {
    size_t  len = literal.length();
    size_t  i = 0;
    bool    dot = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (literal.substr(i, len) == "inf" || literal.substr(i, len) == "nan")
        return (true);
    for (; i < len - 1; i++) {
        if (literal[i] == '.' && !dot)
            dot = true;
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

// Member functions for converting
char ScalarConverter::_toChar(const std::string &literal) {
    if (literal[1] <= 32 || literal[1] > 126)
        throw NonDisplayableException();
    return(literal[1]);
}
int ScalarConverter::_toInt(const std::string &literal) {
    return (std::atoi(literal.c_str()));
}
float ScalarConverter::_toFloat(const std::string &literal) {
    int sign = 1;
    int len = literal.length();
    int i = 0;
    
    if (literal[i] == '-' || literal[i] == '+') {
        if (literal[i] == '-')
            sign = -1;
        i++;
    }
    if (literal.substr(i, len - 1) == "inf")
        return (sign * std::numeric_limits<float>::infinity());
    if (literal.substr(i, len - 1) == "nan")
        return (std::numeric_limits<float>::quiet_NaN());
    return (sign * std::atof(literal.c_str()));
}
double ScalarConverter::_toDouble(const std::string &literal) {
    int sign = 1;
    int len = literal.length();
    int i = 0;
    
    if (literal[i] == '-' || literal[i] == '+') {
        if (literal[i] == '-')
            sign = -1;
        i++;
    }
    if (literal.substr(i, len) == "inf")
        return (sign * std::numeric_limits<double>::infinity());
    if (literal.substr(i, len) == "nan")
        return (std::numeric_limits<double>::quiet_NaN());
    return (sign * std::atof(literal.c_str()));
}

// Exceptions
const char *ScalarConverter::InvalidLiteralException::what() const throw() {
    return (RED "Invalid literal" RESET);
}
const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return (RED "Non displayable" RESET);
}