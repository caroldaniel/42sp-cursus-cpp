/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:46:51 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 17:58:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors and destructor
	WrongCat(void);
	WrongCat(const WrongCat& other);
	virtual ~WrongCat(void);

	// Operator overloads
	WrongCat	&operator=(const WrongCat &other);
};

#endif