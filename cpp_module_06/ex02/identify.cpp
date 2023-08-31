/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:58:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 21:18:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

// Randomly instanciates a Base class
Base* generate(void)
{
    int choice = std::rand() % 3;
    switch (choice) {
        case 0: return (new A);
        case 1: return (new B);
        case 2: return (new C);
        default: return (NULL);
    }
}

/*
** Identifies the type of the Base class using pointers
** ----------------------------------------------------
** When you use dynamic_cast with pointers, if the cast fails, the function returns a null pointer.
** This is because C++ pointers can be null, so dynamic_cast can return a null pointer in case of failure.
*/
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

/*
** Identifies the type of the Base class using references
** ------------------------------------------------------
** When you use dynamic_cast with references, if the cast fails, a std::bad_cast exception is thrown. 
** This is because C++ references cannot be null, so dynamic_cast cannot return a null reference in case of failure. 
** To handle this situation, you need to use try-catch blocks to catch the exception thrown by a failed dynamic_cast. 
** Each try-catch block is used to attempt the cast to a specific derived type. 
** If the cast fails, the exception is caught, and you move on to the next try-catch block.
*/
void identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch(const std::exception& e1) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch(const std::exception& e2) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch(const std::exception& e3) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
