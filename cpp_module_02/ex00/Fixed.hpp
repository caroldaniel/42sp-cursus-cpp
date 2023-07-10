/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:16:12 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/09 17:40:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const int	fractionalBits = 8;
	int					_rawBits;

public:
	// Default Constructor
	Fixed(void);
	// Copy constructor
	Fixed(const Fixed &other);
	// Destructor
	~Fixed(void); 
	// Operator overload
	Fixed	&operator=(const Fixed &other);
	// Setters and getters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif