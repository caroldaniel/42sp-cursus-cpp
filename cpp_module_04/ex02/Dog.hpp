/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:27 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 12:24:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

// Dog Class
class Dog : public AAnimal
{
private:
	Brain	*_brain;
public:
	// Constructors and destructor
	Dog(void);
	Dog(const Dog& other);
	virtual ~Dog(void);

	// Operator overloads
	Dog	&operator=(const Dog& other);

	// Member functions
	virtual void	makeSound(void) const;
};

#endif