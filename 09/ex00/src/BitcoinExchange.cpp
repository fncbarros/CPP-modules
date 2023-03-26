/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:51:47 by fbarros           #+#    #+#             */
/*   Updated: 2023/03/06 19:51:49 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <iostream>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange() :
_exchangeRateMap(readFile("./input-files/data.csv", ','))
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _exchangeRateMap = other._exchangeRateMap;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

Database BitcoinExchange::readFile(const std::string path, char delim)
{
    std::ifstream inputFile(path.c_str());
    char dateBuffer[MAXLINE] = {0};
    float rateBuffer;
    Database mapBuffer;

    // TODO: not handling wrong file name
    inputFile.exceptions(std::istream::badbit);

    try {
        inputFile.is_open();
        inputFile.ignore(MAXLINE, '\n');

        while (inputFile.getline(dateBuffer, MAXLINE, delim).good())
        {
            inputFile >> rateBuffer;
            mapBuffer.insert(std::make_pair(dateBuffer, rateBuffer));
            inputFile.ignore(1); // jumping '\n' char
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    inputFile.close();
    return mapBuffer;
}

void printDatabase(const Database& database)
{
    if (database.size() == 0)
        std::cout << "print: map is empty\n";
    for (Database::const_iterator it = database.begin();
        it != database.end(); 
        it++)
    {
    std::cout << it->first << " " << it->second << std::endl;
    }
}
