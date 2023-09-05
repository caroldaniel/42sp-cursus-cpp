/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:02:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/05 16:34:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** Default constructor
*/
PmergeMe::PmergeMe(void) {
    return ;
}
/*
** Copy constructor
*/
PmergeMe::PmergeMe(PmergeMe const &src) {
    *this = src;
    return ;
}
/*
** Destructor
*/
PmergeMe::~PmergeMe(void) {
    return ;
}
/*
** Operation overload: Assignation operator
*/
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return (*this);
}

/*
** sort() fuction overload for vectors
** -----------------------------------
** Sorts a vector of integers using the Ford-Johnson algorithm
*/
void PmergeMe::sort(std::vector<int> &vector) {
    (void)vector;
    return ;
}

/*
** sort() fuction overload for lists
** ---------------------------------
** Sorts a list of integers using the Ford-Johnson algorithm
*/
void PmergeMe::sort(std::list<int> &list) {
    (void)list;
    return ;
}

/*
** validateSequence() function
*/
bool validateSequence(std::string sequence) {
    std::istringstream iss(sequence);
    std::string token;
    std::vector<int> seenNumbers;
    
    while (iss >> token) {
        if (token.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Error: Only positive integers are allowed." << std::endl;
            return (false);
        }
        int num = std::atoi(token.c_str());
        for (size_t i = 0; i < seenNumbers.size(); i++) {
            if (seenNumbers[i] == num) {
                std::cout << "Error: Only unique numbers are allowed." << std::endl;
                return (false);
            }
        }
        seenNumbers.push_back(num);
    }
    return (true);
}