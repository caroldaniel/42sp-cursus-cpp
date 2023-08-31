/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:07:20 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 18:26:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    std::cout << GREEN << "------ Test 1: empty array ------" << RESET << std::endl;
    std::cout << YELLOW << "Create empty array" << RESET << std::endl;
    Array<int> empty;
    std::cout << YELLOW << "Access empty array" << RESET << std::endl;
    std::cout << "\tSize: " << empty.size() << std::endl;
    try {
        std::cout << YELLOW << "Trying to access index 0: " << RESET << empty[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: array of 5 ints
    std::cout << GREEN << "------ Test 2: array of 5 ints ------" << RESET << std::endl;
    std::cout << "Create array of 5 ints" << std::endl;
    Array<int> five(5);
    std::cout << "Access five array" << std::endl;
    std::cout << "\tSize: " << five.size() << std::endl;
    for (int i = 0; i < five.size(); i++)
        five[i] = i;
    for (int i = 0; i < five.size(); i++)
        std::cout << "\tfive[" << i << "]: " << five[i] << std::endl;
    std::cout << std::endl;

    // Test 3: array of 5 strings
    std::cout << GREEN << "------ Test 3: array of 5 strings ------" << RESET << std::endl;
    std::cout << "Create array of 5 strings" << std::endl;
    Array<std::string> strings(5);
    std::cout << "Access strings array" << std::endl;
    std::cout << "\tSize: " << strings.size() << std::endl;
    strings[0] = "Hello";
    strings[1] = "World!";
    strings[2] = "How";
    strings[3] = "are";
    strings[4] = "you?";
    for (int i = 0; i < strings.size(); i++)
        std::cout << "\tstrings[" << i << "]: " << strings[i] << std::endl;
    std::cout << std::endl;

    // Test 4: copy constructor
    std::cout << GREEN << "------ Test 4: copy constructor ------" << RESET << std::endl;
    std::cout << YELLOW << "Create copy array" << RESET << std::endl;
    Array<std::string> copy(strings);
    std::cout << YELLOW << "Access copy array" << RESET << std::endl;
    std::cout << "\tSize: " << copy.size() << std::endl;
    for (int i = 0; i < copy.size(); i++)
        std::cout << "\tcopy[" << i << "]: " << copy[i] << std::endl;
    std::cout << YELLOW << "Getting the arrays locations" << RESET << std::endl;
    // get the strings array memory location
    std::cout << "\tstrings:\t" << &strings << std::endl;
    // get the copy array memory location
    std::cout << "\tcopy:\t\t" << &copy << std::endl;    
    std::cout << std::endl;

    // Test 5: assignment operator
    std::cout << GREEN << "------ Test 5: assignment operator ------" << RESET << std::endl;
    std::cout << YELLOW << "Create assign array" << RESET << std::endl;
    Array<std::string> assign;
    assign = strings;
    std::cout << YELLOW << "Access assign array" << RESET << std::endl;
    std::cout << "\tSize: " << assign.size() << std::endl;
    for (int i = 0; i < assign.size(); i++)
        std::cout << "\tassign[" << i << "]: " << assign[i] << std::endl;
    std::cout << YELLOW << "Getting the arrays locations" << RESET << std::endl;
    // get the strings array memory location
    std::cout << "\tstrings:\t" << &strings << std::endl;
    // get the assign array memory location
    std::cout << "\tassign:\t\t" << &assign << std::endl;
    std::cout << std::endl;
    
    // Test 6: out of bounds exception
    std::cout << GREEN << "------ Test 6: out of bounds exception ------" << RESET << std::endl;
    std::cout << YELLOW << "Create out array" << RESET << std::endl;
    Array<int> out(5);
    std::cout << YELLOW << "Access out array" << RESET << std::endl;
    std::cout << "\tSize: " << out.size() << std::endl;
    for (int i = 0; i < out.size(); i++)
        out[i] = i;
    for (int i = 0; i < out.size(); i++)
        std::cout << "\tout[" << i << "]: " << out[i] << std::endl;
    try {
        std::cout << "\tTrying to access index 5: " << out[5] << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
