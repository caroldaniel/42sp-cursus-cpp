/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:16:07 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 18:46:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << fractionalBits;
	return ;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << fractionalBits));
	return ;
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Assigment Operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

// Setters and getters
int	Fixed::getRawBits(void) const {
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)_rawBits / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_rawBits >> fractionalBits);
}

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}