/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:46:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 10:01:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
    int a[] = {1, 2, 3, 4, 5};
    std::string b[] = {"one", "two", "three", "four", "five"};

    std::cout << YELLOW << "Printing integers in an array..." << RESET << std::endl;
    ::iter(a, 5, print);
    std::cout << YELLOW << "Printing strings in an array..." << RESET << std::endl;
    ::iter(b, 5, print);
    return (0);
}
