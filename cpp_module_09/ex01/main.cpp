/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:42:08 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/03 22:44:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    RPNEvaluator rpn;

    if (argc != 2) {
        std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
        return (1);
    }
    try {
        std::cout << rpn.evaluate(argv[1]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}