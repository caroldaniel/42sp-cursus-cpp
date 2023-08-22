/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:23:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:40:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

// Animal Class
class Animal
{
protected:
	std::string type;
public:
	// Constructors and destructor
	Animal(void);
	Animal(std::string animal_type);
	Animal(const Animal& other);
	virtual ~Animal(void);

	// Operator overloads
	Animal	&operator=(const Animal& other);

	// Member functions
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

#endif