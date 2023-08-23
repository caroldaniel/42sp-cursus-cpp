/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:34:11 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:21:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

/*
Description: What is a materia? A materia is a magical entity that can be used
to cast spells. It is a virtual class that will be inherited by concrete
classes that will implement the spells. The materia has a type, which is the
name of the spell, and a use function that will be implemented by the concrete
classes. The use function will receive a target as parameter, which will be the
character that will be the target of the spell.
*/

class AMateria
{
protected:
	std::string _type;
public:
	// Constructors and destructor
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &source);
	virtual ~AMateria(void);

	// Operator overloads
	AMateria			&operator=(const AMateria &other);

	// Member functions
	std::string const 	&getType(void) const; //Returns the materia type
	virtual void 		use(ICharacter& target);
	virtual AMateria	*clone(void) const = 0;
};

#endif