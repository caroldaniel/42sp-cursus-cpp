/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:05:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/31 18:11:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"

template <typename T>
class Array
{
private:
    T*		_array;
    int		_size;
public:
    // Constructors and destructor
    Array(void) : _array(NULL), _size(0) {}
    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    Array(Array const& src) {
        this->_array = new T[src._size];
        this->_size = src._size;
        for (int i = 0; i < src._size; i++)
            this->_array[i] = src._array[i];
    }
    ~Array(void) { delete [] this->_array; }
    // Operators
    Array& operator=(Array const& src) {
        if (this != &src)
        {
            delete [] this->_array;
            this->_array = new T[src._size];
            this->_size = src._size;
            for (int i = 0; i < src._size; i++)
                this->_array[i] = src._array[i];
        }
        return (*this);
    }
    T& operator[](int index) {
        if (index < 0 || index >= this->_size)
            throw OutOfBoundsException();
        return (this->_array[index]);
    }
    // Getters and setters
    int size(void) const { return (this->_size); }
    // Exceptions
    class OutOfBoundsException : public std::exception {
        virtual const char* what() const throw() {
            return (RED "Index out of bounds." RESET);
        }
    };
};

#endif