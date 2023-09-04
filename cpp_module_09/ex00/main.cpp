/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:22:55 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/04 19:53:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** Description
** -----------
** You have to create a program which outputs the value of a certain amount of 
** bitcoin on a certain date.
** This program must use a database in csv format which will represent bitcoin 
** price over time. This database is provided within the subject.
** The program will take as input a second database, storing the different 
** prices/dates to evaluate.
** Your program must respect these rules:
** • The program name is btc.
** • Your program must take a file as argument.
** • Each line in this file must use the following format: "date | value".
** • A valid date will always be in the following format: Year-Month-Day.
** • A valid value must be either a float or a positive integer, between 0 and 1000.
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED "Error: invalid number of arguments." RESET << std::endl;
        return (1);
    } else {
        try {
            BitcoinExchange btc;
            btc.readInput(argv[1]);
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            return (1);
        }        
    }
    return (0);
}
