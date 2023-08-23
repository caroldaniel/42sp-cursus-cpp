/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:46:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	// Constructors and destructor
	WrongAnimal(void);
	WrongAnimal(std::string wrongAnimal_type);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	// Operator overloads
	WrongAnimal	&operator=(const WrongAnimal &other);

	// Member functions
	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif