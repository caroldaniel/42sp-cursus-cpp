/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:21:41 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 20:40:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructor
Serializer::Serializer(void) {
    return ;
}
// Destructor
Serializer::~Serializer(void) {
    return ;
}
// Copy constructor
Serializer::Serializer(Serializer const &source) {
    *this = source;
    return ;
}
// Operation overload: Assignation
Serializer &Serializer::operator=(Serializer const &source) {
    if (this != &source)
        *this = source;
    return (*this);
}

// Member functions
uintptr_t Serializer::serialize(Data *ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}
Data *Serializer::deserialize(uintptr_t raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}
