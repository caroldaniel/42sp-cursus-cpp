/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:27:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/01 11:07:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <vector>
# include <list>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

/*
** STACK
** Definition of the stack container class
** ---------------------------------------
** The 'std::stack' class is a container adapter that gives the programmer the
** functionality of a stack - specifically, a LIFO (last-in, first-out) data
** structure.
** The underlying container of the stack is the deque (double-ended queue)
** container class, which allows for fast insertion and deletion at both its
** beginning and its end. The elements are stored contiguously, which means
** that elements can be accessed not only through iterators, but also using
** offsets to regular pointers to elements. This means that a pointer to an
** element of a deque may be passed to any function that expects a pointer to
** an element of an array.
** The deque container is used internally by the stack to store its elements,
** offering a similar interface to the underlying container, with the following
** specificities:
** - The element pushed and popped is the one that is stored at the end of the
**   deque.
** - The iterator returned by member functions 'begin' and 'end' of stack
**   refer to this element.
** - The iterator returned by member function 'end' of stack points to the
**   element following the last element of the deque (not to the last element
**   itself).
** - The iterator returned by member function 'end' of stack can be used as an
**   argument to member function 'erase' of deque, removing all elements from
**   the stack.
** - The underlying container may be any of the standard container class
**   templates or some other specifically designed container class. The
**   container shall support the following operations:
**   - empty
**   - size
**   - front
**   - back
**   - push_back
**   - pop_back
** The standard container classes 'vector' and 'deque' fulfill these
** requirements. By default, if no container class is specified for a
** particular stack class instantiation, the standard container 'deque' is used.
** Member functions:
** (constructor) : Constructs a stack container adaptor object.
** (destructor) : Destroys the container adaptor object.
** empty : Returns whether the stack is empty.
** size : Returns the number of elements in the stack.
** top : Returns a reference to the top element in the stack.
** push : Inserts a new element at the top of the stack, above its current top
**        element.
** emplace : Constructs a new element in-place at the top of the stack, above
**           its current top element.
** pop : Removes the element on top of the stack, effectively reducing its size
**       by one.
** swap : Exchanges the contents of the container adaptor with those of other.
** Non-member function overloads:
** relational operators (stack) : Performs the appropriate comparison operation
**                                between the stack containers lhs and rhs.
** swap (stack) : Exchanges the contents of the container adaptor lhs with
**                those of rhs.
** ---------------------------------------
** More about the stack container class:
** https://www.cplusplus.com/reference/stack/stack/
** ---------------------------------------
** More about the deque container class:
** https://www.cplusplus.com/reference/deque/deque/
** ---------------------------------------
*/

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        // Default Constructor
        MutantStack(void) : std::stack<T>() {}
        // Copy Constructor
        MutantStack(MutantStack const &src) : std::stack<T>(src) {}
        // Destructor
        virtual ~MutantStack(void) {}
        // Assignation operator overload
        MutantStack &operator=(MutantStack const &obj) {
            if (this != &obj)
                std::stack<T>::operator=(obj);
            return (*this);
        }
        // Member functions
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void) {
            return (std::stack<T>::c.begin());
        }
        iterator end(void) {
            return (std::stack<T>::c.end());
        }
};

#endif