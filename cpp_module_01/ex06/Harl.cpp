/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:33 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 18:45:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor & Destructor
Harl::Harl(void)
{
	_filter = DEBUG;
	std::cout << GREEN << std::endl << "Harl is here!" << std::endl << RESET << std::endl;
}

Harl::~Harl(void)
{
	std::cout << GREEN << "Harl is gone!" << std::endl << RESET << std::endl;
}

// Private methods
void	Harl::_debug(void)
{
	std::cout << BLUE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET  << std::endl;
}

void	Harl::_info(void)
{
	std::cout << YELLOW << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET  << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << ORANGE << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET  << std::endl;
}

void	Harl::_error(void)
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

// Public methods
void	Harl::setFilter(const std::string& filter)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i_filter;

	for (i_filter = 0; i_filter < 4; i_filter++) {
		if (levels[i_filter] == filter)
			break ;
	}
	switch (i_filter) {
		case 0:
			_filter = DEBUG;
			break;
		case 1:
			_filter = INFO;
			break;
		case 2:
			_filter = WARNING;
			break;
		case 3:
			_filter = ERROR;
			break;
		default:
			break;
	}
	return ;
}

// Getters
e_Filter	Harl::getFilter(void) const
{
	return (_filter);
}

void	Harl::complain(const std::string& level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*methods[4])(void) = {
		&Harl::_debug, 
		&Harl::_info, 
		&Harl::_warning, 
		&Harl::_error
	};
	
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
		std::cout << WHITE << "Bla bla bla bla... [in the distance]" << RESET << std::endl;
		return ;
	}
	
	for (int i = _filter; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*methods[i])();
			return ;
		}
	}
	std::cout << WHITE << "..." << RESET << std::endl;
	return ;
}
