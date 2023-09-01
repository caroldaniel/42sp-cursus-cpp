/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:15:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 22:36:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

    // Test #1
    std::cout << YELLOW << "------ Test as in subject ------" RESET << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // Test #2 - Exception
    std::cout << YELLOW << "------ Test with exception ------" RESET << std::endl;
    try {
        sp.addNumber(1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test #3 - with a minimum of 10000 elements
    std::cout << YELLOW << "------ Test with a minimum of 10000 elements ------" RESET << std::endl;
    Span sp3 = Span(10000);
    // randomically fill the container
    std::srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        sp3.addNumber(std::rand() % 10000);
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;    

    // Test #4 - with a minimum of 100000 elements using addRange()
    std::cout << YELLOW << "------ Test with a minimum of 100000 elements using addRange() ------" RESET << std::endl;
    Span sp4 = Span(100000);
    std::list<int> lst;
    for (int i = 0; i < 100000; i++)
        lst.push_back(std::rand() % 100000);
    sp4.addRange(lst.begin(), lst.end());
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;

    return (0);
}
