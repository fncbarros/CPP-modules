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
#include <stdint.h>

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
        if (!std::string(dateBuffer).find(delim) || ss.eof())
        {
            std::cerr << "Error: bad input => " << inputline << std::endl;
        }
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
    if (!validDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (value >= static_cast<float>(INT32_MAX))
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::compute(const Entry& entry)
{
    float result = 0;
    
    try {
        result = _exchangeRateMap.at(entry.first) * entry.second;
    }
    catch (const std::exception& e)
    {
        // Inserting new element and finding previous value
        const std::string newDate = entry.first;
        std::pair<Database::iterator, bool> newElem = _exchangeRateMap.insert(Entry(newDate, 0));
        const bool was_inserted = newElem.second;
        Database::iterator itr = newElem.first;
        

        if (itr != _exchangeRateMap.begin())
        {
            float& newValue = itr->second;
            newValue = (--itr)->second;
        }
        else
        {
            itr->second = 0;
        }

        if (was_inserted)
        {
            result = itr->second * entry.second;
        }
    }

    std::cout << entry.first << " => ";
    std::cout << entry.second << " = ";
    std::cout << /* std::fixed << */ result << std::endl;

    return true;
}

bool BitcoinExchange::validDate(const std::string date)
{

    bool valid = true;
    std::stringstream ss;

    if (date.empty())
    {
        return false;
    }
    
    std::string s_year = date.substr(0u, 4u); // year
    std::string s_month =  date.substr(5u, 2u); // month
    std::string s_day = date.substr(8u, 2u); // day

    // check for non-numerics

    ss << s_year << " " << s_month << " " << s_day;

    // Valid year
    unsigned int year = 0u;
    ss >> year;
    valid = year < 9999u;

    // Valid month
    unsigned short month = 0u;
    ss >> month;
    valid = valid && (month <= 12u && month >= 1u);

    // Valid day
    unsigned short day = 0u;
    ss >> day;
    valid = valid && (day >= 1u && day <= 31u);
    // Checking if day of particular month exists
    if (valid && month == 2u)
    {
        valid = (year % 4u == 0u) ? (day <=29u) : (day <= 28u); // checking leap years, because yes
    }
    else if (valid && month <= 7)
    {
        valid = (month % 2) ? (day <= 30u) : (day <= 31u);
    }
    else if (valid)
    {
        valid = (month % 2) ? (day <= 31u) : (day <= 30u);
    }

    return valid;
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
