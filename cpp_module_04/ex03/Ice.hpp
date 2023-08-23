/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:45:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 12:45:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

/*
Description: The Ice class is a concrete class that inherits from the AMateria
class. It has a type, which is the name of the spell, and a use function that
will be implemented by the concrete classes. The use function will receive a
target as parameter, which will be the character that will be the target of the
spell.
*/

class Ice : public AMateria
{
public:
	// Constructors and destructor
	Ice(void);
	Ice(const Ice &source);
	virtual ~Ice(void);

	// Operator overloads
	Ice	&operator=(const Ice &other);

	// Member functions
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif