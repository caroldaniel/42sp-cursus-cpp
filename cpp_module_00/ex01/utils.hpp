/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:33:52 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/22 01:34:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

# include "Contact.hpp"

void setInput(std::string& attribute, const std::string& prompt, const std::string& errorMessage, void (Contact::*setter)(const std::string&));

#endif