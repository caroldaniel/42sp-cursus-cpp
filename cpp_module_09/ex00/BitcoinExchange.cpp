/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:03:18 by cado-car          #+#    #+#             */
/*   Updated: 2023/09/03 17:36:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** Default constructor
*/
BitcoinExchange::BitcoinExchange(void) : _database() {
    return ;
}

/*
** Copy constructor
*/
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    this->_database = src._database;
    return ;
}

/*
** Destructor
*/
BitcoinExchange::~BitcoinExchange(void) {
    return ;
}

/*
** Operator overload
*/
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    this->_database = src._database;
    return (*this);
}

/*
** loadDatabase()
** ---------------
** Loads the database file into the _database map.
** The database file must have the following format:
** date,exchange_rate
** where `date` is a string in the format YYYY-MM-DD, and `exchange_rate` is a float.
*/
void BitcoinExchange::loadDatabase(void) {
    std::string filename = DATA_FILE;
    std::ifstream file(filename.c_str());
    std::string line;
    std::string date;
    std::string value;
    float fvalue;

    if (!file.is_open()) {
        throw DatabaseNotFoundException();
        return ;
    }
    std::getline(file, line);
    if (filename.substr(filename.find_last_of(".") + 1) != "csv" || !_checkHeader(line, DATABASE))
        throw BadDatabaseFormatException();
    else {
        while (std::getline(file, line)) {
            try {
                _checkLine(line, DATABASE);   
            } catch (std::exception &e) {
                throw BadDatabaseFormatException();
                break ;
            }
            date = line.substr(0, line.find(','));
            value = line.substr(line.find(',') + 1);
            fvalue = std::atof(value.c_str());
            _database[date] = fvalue;
        }
    }
    file.close();
    return ;
}

/*
** readInput()
** ------------
** Reads the input file and calculates the BTC value for a given date and value,
** which will print the results to the standard output.
** The input file must have the following format:
** date|value
** where `date` is a string in the format YYYY-MM-DD, and `value` is a float.
*/
void BitcoinExchange::readInput(std::string filename) {    
    std::ifstream file(filename.c_str());
    std::string line;
    std::string date;
    std::string value;
    float fvalue;

    if (!file.is_open())
        throw InputNotFoundException();
    std::getline(file, line);
    if (filename.substr(filename.find_last_of(".") + 1) != "txt" || !_checkHeader(line, INPUT))
        throw BadInputFormatException();
    while (std::getline(file, line)) {
        try {
            _checkLine(line, INPUT);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue ;
        }
        date = line.substr(0, line.find('|'));
        value = line.substr(line.find('|') + 1);
        fvalue = std::atof(value.c_str());
        _btc(date, fvalue);
    }
}

/*
** _btc()
** -----
** Calculates the BTC value for a given date and value.
** The algorithm will search in the _database map for the exchange rate for the given date.
** If there's no key for the given date, it will search for the last exchange rate before the given date.
** The BTC value will be calculated by multiplying the exchange rate by the given value.
** The result will be printed to the standard output in the following format:
** <date> => <value> = <btc_value>
*/
void BitcoinExchange::_btc(std::string date, float value) {
    std::map<std::string, float>::iterator it = _database.find(date);
    std::string last_date;
    float last_value;

    if (it != _database.end()) {
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        return ;
    }
    for (it = _database.begin(); it != _database.end(); it++) {
        if (it->first > date)
            break ;
        last_date = it->first;
        last_value = it->second;
    }
    std::cout << date << " => " << value << " = " << value * last_value << std::endl;
}

/*
** _checkHeader()
** --------------
** Checks if the file has the right format for the given file type.
** For Database, check if the header has only two columns (`date` and `exchange_rate`),
** separated by a comma (`,`).
** For Input, check if the header has only two columns (`date` and `value`),
** separated by a pipe (`|`).
*/
bool BitcoinExchange::_checkHeader(std::string header, file_type type) {
    char        delimiter = type == DATABASE ? ',' : '|';
    std::string column1 = "date";
    std::string column2 = type == DATABASE ? "exchange_rate" : "value";

    // Check if the columns are separated by the right character
    if (std::count(header.begin(), header.end(), delimiter) != 1)
        return (false);
    std::string header1 = header.substr(0, header.find(delimiter));
    std::string header2 = header.substr(header.find(delimiter) + 1);
    _trimCell(header1);
    _trimCell(header2);
    _trimCell(column1);
    _trimCell(column2);
    // Check if the columns have the right names
    if (header1 != column1 || header2 != column2)
        return (false);
    return (true);
}

/*
** _checkLine()
** ------------
** Checks if the line has the right format for the given file type.
** For Database, check if the line has only two columns, separated by a comma (`,`).
** For Input, check if the line has only two columns, separated by a pipe (`|`).
** For both, check if the date and value are in the right format.
** Date must be in the format YYYY-MM-DD, and value must be a float or positive integer.
*/
void BitcoinExchange::_checkLine(std::string line, file_type type) {
    char        delimiter = type == DATABASE ? ',' : '|';
    
    int delimiter_count = std::count(line.begin(), line.end(), delimiter);
    if (delimiter_count != 1) {
        throw BadInputDataException(line);
        return ;
    }
    std::string date = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter) + 1);
    _trimCell(date);
    _trimCell(value);
    if (!date.length() || !value.length())
        throw BadInputDataException(line);
    else if (!_checkDate(date))
        throw BadInputDataException(line);
    else if (!_checkValue(value)) {
        float fvalue;
        try {
            fvalue = std::atof(value.c_str());
        } catch (std::exception &e) {
            throw BadInputDataException(line);
        }
        if (type == INPUT) {
            if (fvalue < 0)
                throw NegativeValueException();
            else if (fvalue > 1000)
                throw TooLargeValueException();
        }
    }
}

/*
** _checkDate()
** ------------
** Checks if the date is in the right format (YYYY-MM-DD).
*/
bool BitcoinExchange::_checkDate(std::string date) {
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return (false);
        } else if (!std::isdigit(date[i]))
            return (false);
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2008 || year > 2023)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1)
        return (false);
    if (month == 2 && day > 29)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}

/*
** _checkValue()
** -------------
** Checks if the value is a positive float or integer.
*/
bool BitcoinExchange::_checkValue(std::string value) {
    bool dot = false;

    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '.') {
            if (dot)
                return (false);
            dot = true;
        }
        else if (!std::isdigit(value[i]))
            return (false);
    }
    float fvalue = std::atof(value.c_str());
    if (fvalue < 0)
        return (false);
    else if (fvalue > 1000)
        return (false);
    return (true);
}

/*
** _trimCell()
** -----------
** Trims the cell string, removing any leading or trailing spaces.
*/
void BitcoinExchange::_trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos)
        cell = "";
    else
        cell = cell.substr(start, end - start + 1);    
}

/*
** DatabaseNotFoundException class
*/
const char *BitcoinExchange::DatabaseNotFoundException::what() const throw() {
    return (RED "Database file not found. Please, make sure there is a `data.csv` file in the root of your repository." RESET);
}
/*
** BadDatabaseHeaderException class
*/
const char *BitcoinExchange::BadDatabaseFormatException::what() const throw() {
    return (RED "Bad format in Database file. Please, make sure your database is a .csv with two columns: `date,exchange_rate`" RESET);
}
/*
** BadDatabaseFormatException class
*/
const char *BitcoinExchange::BadDatabaseDataException::what() const throw() {
    return (RED "Bad data in Database file. Please, make sure your databese is filled correctly." RESET);
}
/*
** InputNotFoundException class
*/
const char *BitcoinExchange::InputNotFoundException::what() const throw() {
    return (RED "Input file not found. Please, make sure your input file exists and has the right permissions." RESET);
}
/*
** BadInputFormatException class
*/
const char *BitcoinExchange::BadInputFormatException::what() const throw() {
    return (RED "Bad format in Input file. Please, make sure your input is a .txt with two columns: `date|value`" RESET);
}
/*
** BadInputDataException class
*/
BitcoinExchange::BadInputDataException::BadInputDataException(std::string line) : _error_message("bad input => " + line) {
    return ;
}
const char *BitcoinExchange::BadInputDataException::what() const throw() {
    return (_error_message.c_str());
}
/*
** NegativeValueException class
*/
const char *BitcoinExchange::NegativeValueException::what() const throw() {
    return ("not a positive number.");
}
/*
** ValueTooLargeException class
*/
const char *BitcoinExchange::TooLargeValueException::what() const throw() {
    return ("too large a number.");
}