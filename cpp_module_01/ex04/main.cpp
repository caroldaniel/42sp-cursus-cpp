/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:22:22 by cado-car          #+#    #+#             */
/*   Updated: 2023/07/04 10:58:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main(int argc, char **argv)
{
	try {
		if (argc != 4) {
			throw std::runtime_error(RED + "Error: wrong number of arguments." + RESET);
		}
		FileReplacer(argv[1], argv[2], argv[3]);
		return (0);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
