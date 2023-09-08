/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:47:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/08 11:27:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <ctime>
# include <string>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"

/*
** PmergeMe
** --------
** This class is responsible for sorting a sequence of positive integers using
** the merge-insert algorithm, also known as the Ford–Johnson algorithm.
** The Ford-Johnson algorithm is a sorting algorithm that combines the merge
** and insertion algorithms. It is a stable, in-place, comparison-based
** algorithm, that has a worst-case time complexity of O(n^2) and a best-case
** time complexity of O(n log n).
** In terms of overhead, the algorithm is not so efficient, since it uses
** computation comparisons to find the insertion point, and its a very well known
** algorithm to reduce the number of comparisons, keeping a good efficiency for 
** smaller sequences.
** -------------------------
** About the class structure
** -------------------------
** The class will be constructed with a string of positive integers, that will be
** validated and stored in a private string variable. The class will have
** a public member function called `sort`. Using function overload, the `sort`
** should be able to receive a vector or a list of integers, and sort them using
** the Ford-Johnson algorithm.
*/

class PmergeMe {
    private:
        // Constructors and destructors
        PmergeMe(void);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);
        // Operation overload
        PmergeMe &operator=(PmergeMe const &rhs);
        // Private member functions
        static void _sort_pairs(std::vector<std::pair<int, int> > &vector, size_t size);
        static void _sort_pairs(std::list<std::pair<int, int> > &list, size_t size);
            
    public:
        static void sort(std::vector<int> &vector);
        static void sort(std::list<int> &list);
};

/*
** validate_sequence()
** ------------------
** This function will receive a string of positive integers and validate it.
*/
bool validate_sequence(std::string sequence);

/*
** parse_sequence
** -------------
** This function will receive a string of positive integers and parse it into
** either a vector or a list of integers. It will validate the string and
** throw an exception if it is not valid.
** The string will only be valid if it contains positive integers separated by
** spaces, and no other characters.
*/
template <typename T>
T parse_sequence(std::string sequence) {
    T container;
    std::stringstream iss(sequence);
    int num;

    while (iss >> num)
        container.push_back(num);
    return (container);
}

/*
** print_sequence
** -------------
** This function will receive a container of integers and print it to the
** standard output, separated by spaces.
*/
template <typename T>
void print_sequence(T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

/*
** print_pairs
** -----------
** This function will receive a container of pairs of integers and print it to
** the standard output, separated by spaces.
*/
template <typename T>
void print_pairs(T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        std::cout << "(" << it->first << ", " << it->second << ")";
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

/*
** Jacobsthal sequence
*/
int jacobsthal(int n);

/*
** _generate_insertion_sequence()
** -----------------------------
** This function will receive a positive integer and return a container with 
** the sequence of indexes to be used in the insertion sort algorithm.
** These numbers will be defined by the Jacobsthal sequence in the following
** manner:
** 1. The sequence will start with the third number of the Jacobsthal sequence.
** 2. The next element will be the next Jacobsthal number.
** 3. Then, you will proceed to decrement the last Jacobsthal number by 1, and
**    insert it in the sequence. Do it in a loop until you reach a number that
**    is already in the sequence.
** 4. Repeat steps 2 and 3 until you reach the desired size.
*/
template <typename T>
T generate_insertion_sequence(size_t size) {
    T sequence;
    int jacobsthal_index = 2;
    
    sequence.push_back(jacobsthal(jacobsthal_index));
    while (sequence.size() < size - 2) {
        jacobsthal_index++;
        sequence.push_back(jacobsthal(jacobsthal_index));
        while (std::find(sequence.begin(), sequence.end(), sequence.back() - 1) == sequence.end()) {
            sequence.push_back(sequence.back() - 1);
        }
    }
    return (sequence);
}

/*
** Compare vectors
*/


#endif