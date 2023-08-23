/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:29:55 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:10:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

// Cat Class
class Cat : public AAnimal
{
private:
	Brain	*_brain;
public:
	// Constructors and destructor
	Cat(void);
	Cat(const Cat& other);
	virtual ~Cat(void);

	// Operator overloads
	Cat	&operator=(const Cat& other);

	// Member functions
	virtual void	makeSound(void) const;
};

#endif