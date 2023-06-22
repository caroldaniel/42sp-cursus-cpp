/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:04:22 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/22 01:20:58 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
	private:
		// Attributes
		static const int _MAX_CONTACTS = 8;
		Contact	_contacts[_MAX_CONTACTS];
		int		_index;
		int		_contactCount;
	public:
		// Constructors and destructors
		Phonebook();
		~Phonebook();
		// Methods
		void	addContact();
		void	searchContact();
};

#endif