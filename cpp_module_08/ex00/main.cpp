/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:40:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 21:27:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    // Test with a container list of 5 ints
    std::cout << YELLOW << "------ Test with a container list of ints ------" RESET << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i);
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(lst, 3) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(lst, 5) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test with a container vector of 5 ints
    std::cout << YELLOW << "------ Test with a container vector of ints ------" RESET << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(vec, 3) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(vec, 5) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test with a container deque of 5 ints
    std::cout << YELLOW << "------ Test with a container deque of ints ------" RESET << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 5; i++)
        deq.push_back(i);
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(deq, 3) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(deq, 5) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
  
    return (0);
}
