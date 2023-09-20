/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:58:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/20 16:18:51 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors and destructor
Span::Span(unsigned int n) : _n(n) {
    return ;
}
Span::Span(const Span &source) {
	this->_n = source.getN();
    const std::vector<int>& sourceVec = source.getVec();
    for (size_t i = 0; i < sourceVec.size(); i++)
        this->_vec.push_back(sourceVec[i]);
    return ;
}
Span::~Span() {
    return ;
}

// Operators overload
Span &Span::operator=(const Span &source) {
    this->_n = source.getN();
    const std::vector<int>& sourceVec = source.getVec();
    for (size_t i = 0; i < sourceVec.size(); i++)
        this->_vec.push_back(sourceVec[i]);
    return (*this);
}

// Member functions
void    Span::addNumber(int n) {
    if (this->_vec.size() == this->_n)
        throw FullContainerException();
    this->_vec.push_back(n);
    return ;
}
int     Span::shortestSpan(void) {
    if (this->_vec.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
        if (*(it + 1) - *it < shortest)
            shortest = *(it + 1) - *it;
    return (shortest);
}
int     Span::longestSpan(void) {
    if (this->_vec.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

// Getters and setters
unsigned int        Span::getN(void) const {
    return (this->_n);
}
std::vector<int>    Span::getVec(void) const {
    return (this->_vec);
}

// Exception class
const char *Span::FullContainerException::what() const throw() {
    return (RED "Container is full." RESET);
}
const char *Span::NotEnoughElementsException::what() const throw() {
    return (RED "Not enough elements in container." RESET);
}
