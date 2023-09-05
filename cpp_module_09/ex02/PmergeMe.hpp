/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:47:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/05 16:31:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
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
    public:
        static void sort(std::vector<int> &vector);
        static void sort(std::list<int> &list);
};

/*
** validateSequence()
** ------------------
** This function will receive a string of positive integers and validate it.
*/
bool validateSequence(std::string sequence);

/*
** parseSequence
** -------------
** This function will receive a string of positive integers and parse it into
** either a vector or a list of integers. It will validate the string and
** throw an exception if it is not valid.
** The string will only be valid if it contains positive integers separated by
** spaces, and no other characters.
*/

template <typename T>
T parseSequence(std::string sequence) {
    T container;
    std::stringstream iss(sequence);
    int num;

    while (iss >> num)
        container.push_back(num);
    return (container);
}

/*
** printSequence
** -------------
** This function will receive a container of integers and print it to the
** standard output, separated by spaces.
*/
template <typename T>
void printSequence(T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

#endif