/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:31 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 18:30:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

// Colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string WHITE = "\033[1;37m";
const std::string ORANGE = "\033[1;38;5;202m";

enum e_Filter {
    DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
private:
	e_Filter	_filter;
	// Private methods
	void		_debug(void);
	void		_info(void);
	void		_warning(void);
	void		_error(void);

public:
	// Constructor & Destructor
	Harl(void);
	~Harl(void);
	// Setters
	void		setFilter(const std::string& filter);
	// Getters
	e_Filter	getFilter(void) const;
	// Member functions
	void		complain(const std::string& level);
};

#endif