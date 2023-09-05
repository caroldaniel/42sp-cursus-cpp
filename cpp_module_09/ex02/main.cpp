/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:45:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/05 16:36:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./PmergeMe \"<sequence of unique positive integers>\"" << std::endl;
        return (1);
    } else if (!validateSequence(argv[1])) {
        return (1);
    }
    
    // Sort vector
    std::vector<int> vector = parseSequence< std::vector<int> >(argv[1]);
    PmergeMe::sort(vector);
    printSequence(vector);

    // Sort list    
    std::list<int> list = parseSequence< std::list<int> >(argv[1]);
    PmergeMe::sort(list);
    printSequence(list);
    return (0);
}
