/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:45:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/08 22:07:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./PmergeMe \"<sequence of unique positive integers>\"" << std::endl;
        return (1);
    } else if (!validate_sequence(argv[1])) {
        return (1);
    }

    // Control vector
    std::vector<int> control_vector = parse_sequence<std::vector<int> >(argv[1]);
    if (control_vector.size() == 0) {
        std::cout << "Error: empty sequence" << std::endl;
        return (1);
    }
    std::cout << "Before: ";
    print_sequence(control_vector);
    std::sort(control_vector.begin(), control_vector.end());
    std::cout << "After: ";
    print_sequence(control_vector);

    // Control list
    std::list<int> control_list = parse_sequence<std::list<int> >(argv[1]);
    control_list.sort();
    
    // Sort vector
    clock_t vector_start = clock();
    std::vector<int> vector = parse_sequence<std::vector<int> >(argv[1]);
    PmergeMe::sort(vector);
    clock_t vector_end = clock();
    double vector_duration = double(vector_end - vector_start) / CLOCKS_PER_SEC * 1e6;
    if (std::equal(control_vector.begin(), control_vector.end(), vector.begin()))
        std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vector_duration << " us" << std::endl;
    else
        std::cout << RED << "Error: vector not sorted" << RESET << std::endl;

    // Sort list
    clock_t list_start = clock();
    std::list<int> list = parse_sequence<std::list<int> >(argv[1]);
    PmergeMe::sort(list);
    clock_t list_end = clock();
    double list_duration = double(list_end - list_start) / CLOCKS_PER_SEC * 1e6;
    if (std::equal(control_list.begin(), control_list.end(), list.begin()))
        std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << list_duration << " us" << std::endl;
    else
        std::cout << RED << "Error: list not sorted" << RESET << std::endl;    
    return (0);
}
