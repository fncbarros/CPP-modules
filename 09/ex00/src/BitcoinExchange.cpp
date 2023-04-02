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
                std::pair<Entry, bool> element = readLine(buffer, delim);
                if (element.second == true)
                {
                    mapBuffer.insert(element.first);
                }
            }
        } 

        inputFile.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return mapBuffer;
}

std::pair<BitcoinExchange::Entry, bool> BitcoinExchange::readLine(const std::string& inputline, char delim)
{
    std::stringstream ss(inputline);
    char dateBuffer[MAXLINE];
    float valueBuffer(0);
    const char *headLine("date");
    std::pair<Entry, bool> returnVal(std::make_pair("", float(0)), false);

    if (!ss.getline(dateBuffer, MAXLINE, delim).good())
    {
        if (!std::string(dateBuffer).find(delim))
        {
            std::cerr << dateBuffer << "Error: Wrong format" << std::endl;
        }
        else if (ss.eof())
        {
            std::cerr << dateBuffer << "Error: Missing value" << std::endl;
        }
        return returnVal;
    }

    if (!std::string(dateBuffer).find(headLine, 0, 4))
    {
        return returnVal;
    }

    if (ss.eof())
    {
        return returnVal;
    }

    ss >> valueBuffer;

    returnVal.first.first = dateBuffer;
    returnVal.first.second = valueBuffer;
    returnVal.second = true;

    return returnVal;
}

// 
bool BitcoinExchange::validate(const std::string date, const float value)
{
    size_t start = 0;
    size_t end = date.find('-');
    std::stringstream ss;

    if (date.empty())
    {
        return false;
    }
    
    ss << date.substr(start, end);
    start = end + 1;
    end = date.find('-', start);
    ss << date.substr(start, end);
    ss << date.at(end + 1);

    std::cout << std::string(ss.str()) << std::endl;
    std::cout << date << ": " << _exchangeRateMap[date] << " * " << value << " = " << _exchangeRateMap[date] * value << std::endl;
    return true;
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

void printDatabase(const char *path)
{
	std::ifstream inputFile;
    char buffer[MAXLINE] = {0};
    BitcoinExchange btcEx;

    inputFile.open(path);
    // TODO: not handling wrong file name
    inputFile.exceptions(std::istream::badbit);

    if (inputFile.is_open())
    {
            while (inputFile.getline(buffer, MAXLINE).good())
            {
                std::pair<BitcoinExchange::Entry, bool> element = btcEx.readLine(buffer, '|');
                if (element.second)
                {
					std::cout << element.first.first << " " << element.first.second << std::endl;
				}
			}
	}
    else
    {
		std::cerr << "Error: could not open file.\n";
    }
}
