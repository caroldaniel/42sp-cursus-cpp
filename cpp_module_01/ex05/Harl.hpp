/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:31 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 16:56:38 by cado-car         ###   ########.fr       */
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

class Harl
{
private:
	// Private methods
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

public:
	// Constructor & Destructor
	Harl(void);
	~Harl(void);
	// Member functions
	void	complain(const std::string& level);
};

#endif