/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:10:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 19:24:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
    std::string input;
    while (1) {
        std::cout << "Enter a literal (or type 'exit'): ";
        std::getline(std::cin, input);
        if (input == "exit")
            break ;
        ScalarConverter::convert(input);
    }
}