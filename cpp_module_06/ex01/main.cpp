/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:41:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/11 12:27:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    std::cout << std::endl << YELLOW << "Creating data..." << RESET << std::endl;
    Data *data = new Data("Hello", "World", 42);
    std::cout << "Data is in pointer: \t\t" << data << std::endl;
    std::cout << "Public data is: \t\t" << data->publicData << std::endl;
    std::cout << "Private data is: \t\t" << data->getPrivateData() << std::endl;
    std::cout << "Private number is: \t\t" << data->getPrivateNumber() << std::endl;

    std::cout << std::endl << YELLOW << "Serializing..." << RESET << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Raw pointer is: \t\t" << raw << std::endl;

    std::cout << std::endl << YELLOW << "Deserializing..." << RESET << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Raw is still pointing at: \t" << ptr << std::endl;
    std::cout << "Public data is: \t\t" << ptr->publicData << std::endl;
    std::cout << "Private data is: \t\t" << ptr->getPrivateData() << std::endl;
    std::cout << "Private number is: \t\t" << ptr->getPrivateNumber() << std::endl;

    delete data;
    return (0);
}
