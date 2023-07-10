/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:16:12 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 18:13:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int	fractionalBits = 8;
	int					_rawBits;

public:
	// Constructors
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	// Destructor
	~Fixed(void); 
	// Assignment Operator overload
	Fixed	&operator=(const Fixed &other);
	// Member functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif