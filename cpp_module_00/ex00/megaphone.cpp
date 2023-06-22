/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:19:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 23:54:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

static void	stringToUppercase(std::string &str);

const std::string DEFAULT = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

int	main(int argc, char **argv) {
	int	i;
	
	if (argc == 1) {
		std::cout << DEFAULT << std::endl;
		return (0);
	}
	for (i = 1; i < argc; i++) {
		std::string arg = argv[i];
		stringToUppercase(arg);
		std::cout << arg;
	}
	std::cout << std::endl;
}

static void	stringToUppercase(std::string &str) {
	std::string::iterator it;
	
	for (it = str.begin(); it < str.end(); ++it) {
		*it = std::toupper(*it);
	}
}
