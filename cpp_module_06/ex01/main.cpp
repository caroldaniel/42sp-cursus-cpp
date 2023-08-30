/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:41:19 by cado-car          #+#    #+#             */
/*   Updated: 2023/08/30 20:48:07 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    std::cout << std::endl << YELLOW << "Creating data..." << RESET << std::endl;
    Data *data = new Data();
    std::cout << "Data is in pointer: \t\t" << data << std::endl;

    std::cout << std::endl << YELLOW << "Serializing..." << RESET << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Raw pointer is: \t\t" << raw << std::endl;

    std::cout << std::endl << YELLOW << "Deserializing..." << RESET << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Raw is still pointing at: \t" << ptr << std::endl;

    delete data;
    return (0);
}
