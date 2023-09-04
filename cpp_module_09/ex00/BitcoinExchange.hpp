/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:50:44 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/04 20:35:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

/*
** BitcoinExchange
** ---------------
** This class is responsible for reading the database and input files, and
** calculating the BTC value for a given date and value.
** For this purpose, it uses a `map` to store the database values, and it
** prints the results to the standard output as it reads the input file.
*/

// Global const variable for the data.csv file
# define DATA_FILE	"data.csv"

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

// File type enumeration
enum file_type {
    DATABASE,
    INPUT
};

// BitcoinExchange "static" class - non-instantiable
class BitcoinExchange {
private:
    // Copy constructor and assignment operator
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    // Attributes
    std::map<std::string, float> _database;
    std::string _min_date;
    std::string _max_date;
    // Member functions
    void _loadDatabase(void);    
    void _btc(std::string date, float value);
    bool _checkHeader(std::string line, file_type type);
    void _checkLine(std::string line, file_type type);
    bool _checkDate(std::string date, file_type type);
    bool _checkValue(std::string value, file_type type);
    void _trimCell(std::string &cell);

public:
    // Constructors and destructor
    BitcoinExchange(void);
    ~BitcoinExchange(void);
    // Member functions
    void readInput(std::string filename);

    // Exception classes
    class DatabaseLoadException : public std::exception {
        public:
            DatabaseLoadException(std::string error_message);
            virtual ~DatabaseLoadException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class DatabaseNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseDataException : public std::exception {
        virtual const char *what() const throw();
    };
    class InputNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputDataException : public std::exception {
        public:
            BadInputDataException(std::string line);
            virtual ~BadInputDataException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class BadDateException : public std::exception {
        public:
            BadDateException(std::string date);
            virtual ~BadDateException(void) throw() {};
            virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class NegativeValueException : public std::exception {
        virtual const char *what() const throw();
    };
    class TooLargeValueException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif