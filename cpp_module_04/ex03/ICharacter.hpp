/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:36:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:15:36 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

/*
Description: The ICharacter interface class is the base class for the Character
class. It has a name and a pointer to an array of 4 AMateria pointers. It has
a virtual destructor and a pure virtual function called equip that will be
implemented by the Character class. The equip function will receive an AMateria
pointer as parameter and will equip it in the first empty slot of the array.
The ICharacter class also has a pure virtual function called unequip that will
be implemented by the Character class. The unequip function will receive an
integer as parameter and will unequip the materia in the slot of the array
corresponding to the index received as parameter. The ICharacter class also has
a pure virtual function called use that will be implemented by the Character
class. The use function will receive an integer as parameter and will use the
materia in the slot of the array corresponding to the index received as
parameter.
*/

class AMateria;

class ICharacter
{
public:
	// Constructors and destructor
	virtual ~ICharacter(void) {};
	// Member functions
	virtual std::string const &getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif