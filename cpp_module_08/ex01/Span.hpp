/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:55:08 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 22:23:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>
# include <stdexcept>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

// Span Class
class Span {
private:
    unsigned int        _n;
    std::vector<int>    _vec;
public:
    // Constructors and destructor
    Span(unsigned int n);
    Span(const Span &source);
    ~Span();

    // Operators overload
    Span &operator=(const Span &source);

    // Member functions
    void    addNumber(int n);
    int     shortestSpan(void);
    int     longestSpan(void);
    
    // Fill container using a range of iterators
    template <typename T>
    void    addRange(T begin, T end) {
        if (this->_vec.size() + std::distance(begin, end) > this->_n) {
            std::cout << "Here" << std::endl;
            throw FullContainerException();
        }
        this->_vec.insert(this->_vec.end(), begin, end);
        return ;
    }

    // Getters and setters
    unsigned int        getN(void) const;
    std::vector<int>    getVec(void) const;

    // Exception class
    class FullContainerException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif