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
#include <map>
#include <utility>

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

BitcoinExchange::Database BitcoinExchange::readFile(const std::string path, char delim)
{
    std::ifstream inputFile(path.c_str());
    char buffer[MAXLINE] = {0};
    Database mapBuffer;

    // TODO: not handling wrong file name
    inputFile.exceptions(std::istream::badbit);

    try {
    if (inputFile.is_open())
    {
            while (inputFile.getline(buffer, MAXLINE).good())
            {
                Entry element = readLine(buffer, delim);
                if (element.first == "")
                {
                    continue ;
                }
                mapBuffer.insert(element);
            }
        } 

        inputFile.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return mapBuffer;
}

std::pair<std::string, float> BitcoinExchange::readLine(const std::string& inputline, char delim)
{
    std::stringstream ss(inputline);
    char dateBuffer[MAXLINE];
    float valueBuffer(0);

    if (!ss.getline(dateBuffer, MAXLINE, delim).good())
    {
        return std::make_pair("", float(0));
    }

    if (std::string(dateBuffer) == "date")
    {
        return std::make_pair("", float(0));
    }

    ss >> valueBuffer;

    return std::make_pair(dateBuffer, valueBuffer);
}

void BitcoinExchange::validate(const std::pair<std::string, float>& pair)
{
    (void)pair;
    // const std::string date(pair.first);
    // const float value(pair.second);


}

void printDatabase(const BitcoinExchange::Database& database)
{
    if (database.size() == 0)
        std::cout << "print: map is empty\n";
    for (BitcoinExchange::Database::const_iterator it = database.begin();
        it != database.end(); 
        it++)
    {
    std::cout << it->first << " " << it->second << std::endl;
    }
}
