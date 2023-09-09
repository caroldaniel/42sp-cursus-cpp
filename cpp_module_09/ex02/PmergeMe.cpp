/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:02:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/08 21:57:06 by cado-car         ###   ########.fr       */
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
    // count number of elements
    if (vector.size() <= 1)
        return ;
    /*
    ** Step #1: Straggler Catch
    */
    int straggler = -1;
    if (vector.size() % 2 != 0) {
        straggler = vector.back();
        vector.pop_back();
    }
    /*
    ** Step #2: Create sorted pairs
    */
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vector.size(); i += 2) {
        if (vector[i] < vector[i + 1])
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
        else 
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
    }
    /*
    ** Step #3: Recursively sort all pairs by their largest element using an
    ** adapted `merge sort` algorithm.
    */
    _sort_pairs(pairs, pairs.size());
    /*
    ** Step #4: Pass the sorted elements to the sorted vector and create a pend 
    ** vector to hold the unsorted sequence.
    */
    std::vector<int> sorted;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        sorted.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    if (straggler != -1)
        pend.push_back(straggler);

    /*
    ** Step #5: Insert the first pend element to the beginning of the sorted
    ** sequence.
    */
    sorted.insert(sorted.begin(), pend[0]);
    /*
    ** Step #6: Insert the pend elements into the sorted sequence using the
    ** generated insertion sequence.
    */
    std::vector<int> insertion_order = generate_insertion_sequence<std::vector<int> >(pend.size() - 1);
    if (insertion_order.size() != 0) {
        for (size_t i = 0; i < pend.size() - 1; i++) {
            int element = pend[insertion_order[i]];
            if (element < sorted[0]) {
                sorted.insert(sorted.begin(), element);
            } else {
                for (size_t j = 0; j < sorted.size(); j++) {
                    if (element > sorted[j] && (element < sorted[j + 1] || j == sorted.size() - 1)) {
                        sorted.insert(sorted.begin() + j + 1, element);
                        break ;
                    }
                }
            }
        }
    }
    vector = sorted;
    return ;
}

/*
** _sort_pairs() function overload for vectors
** -------------------------------------------
** This function will receive a vector of pairs of integers and recursively
** sort them by their largest element, using the `merge insert` algorithm.
*/
void PmergeMe::_sort_pairs(std::vector<std::pair<int, int> > &vector, size_t size) {
    // base case: 0 or 1 element
    if (size <= 1)
        return ;
    // divide them into left and right halves
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;
    for (size_t i = 0; i < size / 2; i++)
        left.push_back(vector[i]);
    for (size_t i = size / 2; i < size; i++)
        right.push_back(vector[i]);
    // recursively sort each half
    _sort_pairs(left, left.size());
    _sort_pairs(right, right.size());
    // merge the sorted halves
    size_t i = 0; // index for left half
    size_t j = 0; // index for right half
    size_t k = 0; // index for merged vector
    // merge the two halves back into the original vector
    while (i < left.size() && j < right.size()) {
        // if left element is smaller than right element, insert left element
        if (left[i].first < right[j].first)
            vector[k++] = left[i++];
        else
            vector[k++] = right[j++];
    }
    // copy remaining elements of left half
    while (i < left.size()) 
        vector[k++] = left[i++];
    // copy remaining elements of right half
    while (j < right.size())
        vector[k++] = right[j++];
    return ;   
}

/*
** sort() fuction overload for lists
** ---------------------------------
** Sorts a list of integers using the Ford-Johnson algorithm
*/
void PmergeMe::sort(std::list<int> &list) {
    if (list.size() <= 1)
        return ;
    /*
    ** Step #1: Straggler Catch
    */
    int straggler = -1;
    if (list.size() % 2 != 0) {
        straggler = list.back();
        list.pop_back();
    }
    /*
    ** Step #2: Create sorted pairs
    */
    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
        int first = *it++;
        int second = *it;
        if (first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }
    /*
    ** Step #3: Recursively sort all pairs by their largest element using an
    ** adapted `merge sort` algorithm.
    */
    _sort_pairs(pairs, pairs.size());
    /*
    ** Step #4: Pass the sorted elements to the sorted list and create a pend
    ** list to hold the unsorted sequence.
    */
    std::list<int> sorted;
    std::list<int> pend;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        sorted.push_back(it->first);
        pend.push_back(it->second);
    }
    if (straggler != -1)
        pend.push_back(straggler);
    /*
    ** Step #5: Insert the first pend element to the beginning of the sorted
    ** sequence.
    */
    sorted.push_front(pend.front());
    /*
    ** Step #6: Insert the pend elements into the sorted sequence using the
    ** generated insertion sequence.
    */

    std::list<int> insertion_order = generate_insertion_sequence<std::list<int> >(pend.size() - 1);
    if (insertion_order.size() != 0) {
        for (std::list<int>::iterator it = insertion_order.begin(); it != insertion_order.end(); it++) {
            int element_index = *it;
            std::list<int>::iterator itp = pend.begin();
            std::advance(itp, element_index);
            int element = *itp;
            if (element < sorted.front()) {
                sorted.push_front(element);
            } else {
                std::list<int>::iterator current;
                std::list<int>::iterator next;
                for (std::list<int>::iterator its = sorted.begin(); its != sorted.end(); its++) {
                    current = its++;
                    next = its;
                    if (element > *current && (element < *next || its == sorted.end()))
                        break ;
                    its = current;
                }
                sorted.insert(next, element);
                
            }
        }
    }
    list = sorted;
    return ;
}

/*
** _sort_pairs() function overload for lists
** -----------------------------------------
** This function will receive a list of pairs of integers and recursively
** sort them by their largest element, using the `merge insert` algorithm.
*/
void PmergeMe::_sort_pairs(std::list<std::pair<int, int> > &list, size_t size) {
    // base case: 0 or 1 element
    if (size <= 1)
        return ;
    // divide them into left and right halves
    std::list<std::pair<int, int> > left;
    std::list<std::pair<int, int> > right;
    std::list<std::pair<int, int> >::iterator it = list.begin();
    for (size_t i = 0; i < size / 2; i++) {
        left.push_back(*it++);
    }
    for (size_t i = size / 2; i < size; i++)
        right.push_back(*it++);
    // clear original list
    list.clear();
    // recursively sort each half
    _sort_pairs(left, left.size());
    _sort_pairs(right, right.size());
    // merge the sorted halves
    while (right.size() && left.size()) {
        if (left.front().first < right.front().first) {
            list.push_back(left.front());
            left.pop_front();
        } else {
            list.push_back(right.front());
            right.pop_front();
        }
    }
    // copy remaining elements of left half
    while (left.size()) {
        list.push_back(left.front());
        left.pop_front();
    }
    // copy remaining elements of right half
    while (right.size()) {
        list.push_back(right.front());
        right.pop_front();
    }    
    return ;
}

/*
** validate_sequence() function
*/
bool validate_sequence(std::string sequence) {
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

/*
** jacobsthal()
** ------------
** This function will receive a positive integer and return the corresponding
** Jacobsthal number.
*/
int jacobsthal(int n) {
    if (n <= 1)
        return (n);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
