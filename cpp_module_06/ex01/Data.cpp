/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:29:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/11 12:28:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : publicData("publicData"), _privateData("privateData"), _privateNumber(0) {
    return ;
}
Data::Data(std::string public_data, std::string private_data, int private_number) : publicData(public_data), _privateData(private_data), _privateNumber(private_number) {
    return ;
}
Data::~Data(void) {
    return ;
}
Data::Data(Data const &source) {
    *this = source;
    return ;
}
Data &Data::operator=(Data const &source) {
    if (this != &source)
    {
        this->publicData = source.publicData;
        this->_privateData = source._privateData;
        this->_privateNumber = source._privateNumber;
    }
    return (*this);
}

// Getters
std::string Data::getPrivateData(void) const {
    return (this->_privateData);
}
int Data::getPrivateNumber(void) const {
    return (this->_privateNumber);
}
