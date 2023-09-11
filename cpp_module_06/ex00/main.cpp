/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:10:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/11 11:13:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert \"<literal>\"" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}