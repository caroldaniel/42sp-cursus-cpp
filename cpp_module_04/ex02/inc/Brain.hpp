/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:16:36 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/22 18:17:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	// Constructors and destructor
	Brain(void);
	Brain(const Brain &source);
	~Brain(void);

	// Operator overloads
	Brain	&operator=(const Brain &other);

	// Member functions
	std::string	*getIdeas(void);
};

#endif