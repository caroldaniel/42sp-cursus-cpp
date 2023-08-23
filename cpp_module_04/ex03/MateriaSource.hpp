/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 16:07:24 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

/*
Description: The MateriaSource class is a class that implements the IMateriaSource
interface class. It has a pointer to an array of 4 AMateria pointers. It has a
virtual destructor and a pure virtual function called createMateria that will be
implemented by the MateriaSource class. The createMateria function will receive
a string and return a pointer to an AMateria object.
*/

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_inventory[4];
public:
	// Constructors and destructor
	MateriaSource(void);
	MateriaSource(const MateriaSource &source);
	virtual ~MateriaSource(void);

	// Operator overloads
	MateriaSource	&operator=(const MateriaSource &other);

	// Member functions
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const &type);
};

#endif