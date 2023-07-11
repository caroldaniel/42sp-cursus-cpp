/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:41:53 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/11 16:20:26 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

static bool		check_args(int argc, char **argv);
static bool 	isNumeric(const std::string& str);
static Fixed	*get_args(char **argv);

int	main(int argc, char **argv) {
	Fixed *args;
	// check if arguments are valid
	if (!check_args(argc, argv))
		return (1);
	args = get_args(argv);
	
	// create point
	Point point = Point(args[0], args[1]);
	// create triangle
	Point a = Point(args[2], args[3]);
	Point b = Point(args[4], args[5]);
	Point c = Point(args[6], args[7]);
	if (a == b || a == c || b == c) {
		std::cout << "Error: invalid triangle." << std::endl;
		return (1);
	}
	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	delete [] args;
	return (0);
}

static bool	check_args(int argc, char **argv) {
	// check if the number of arguments is correct
	if (argc != 9) {
		std::cout << "Error: invalid number of arguments." << std::endl;
		return (false);
	}
	// Check if the arguments are numeric
	for (int i = 1; i < argc; ++i) {
        if (!isNumeric(argv[i])) {
			std::cout << "Error: invalid argument." << std::endl;
            return false;  // If any argument is not numeric, return false
        }
    }
	return (true);
}

static bool isNumeric(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

static Fixed	*get_args(char **argv)
{
	Fixed *args = new Fixed[8];
	for (int i = 0; i < 8; i++)
		args[i] = Fixed(static_cast<float>(std::atof(argv[i + 1])));
	return (args);
}
