/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:41:53 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/10 13:01:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"
#include <cstdlib>

static bool		check_args(int argc, char **argv);
static Fixed	*get_args(char **argv);

int	main(int argc, char **argv)
{
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
	Triangle triangle = Triangle(a, b, c);
	// Check if the point is inside the triangle
	if (triangle.containsPoint(point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is outside the triangle." << std::endl;
	delete [] args;
	return (0);
}

static bool	check_args(int argc, char **argv)
{
	// check if the number of arguments is correct
	if (argc != 9) {
		std::cout << "Error: invalid number of arguments." << std::endl;
		return (false);
	}
	// Check if the arguments are numeric
	for (int i = 1; i < argc; i++) {
		bool dot = false;
		for (int j = argv[i][0] == '-' || argv[i][0] == '+' ? 1 : 0; argv[i][j]; j++) {
			if (argv[i][j] == '.' && !dot)
				dot = true;
			else if (!std::isdigit(argv[i][j])) {
				std::cout << "Error: invalid argument." << std::endl;
				return (false);
			}
		}
		return (true);
	}
	return (true);
}

static Fixed	*get_args(char **argv)
{
	Fixed *args = new Fixed[8];
	for (int i = 0; i < 8; i++)
		args[i] = Fixed(static_cast<float>(std::atof(argv[i + 1])));
	return (args);
}
