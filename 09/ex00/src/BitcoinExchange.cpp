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
#include <sstream>

BitcoinExchange::BitcoinExchange()
    : _exchangeRateMap(readCSVFile("./input-files/data.csv", ','))
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

BitcoinExchange::Database BitcoinExchange::readCSVFile(const char *path, const char delim)
{
    std::ifstream inputFile(path);
    std::string buffer;
    Database mapBuffer;

    if (inputFile.is_open())
    {
        while (std::getline(inputFile, buffer).good())
        {
            std::pair<Entry, bool> element = readLine(buffer, delim);
            if (element.second == true)
            {
                mapBuffer.insert(element.first);
            }
        }
    }
    else
    {
        std::cerr << "Error: Could not open " << path << std::endl;
    }

    inputFile.close();

    return mapBuffer;
}

std::pair<BitcoinExchange::Entry, bool> BitcoinExchange::readLine(const std::string& inputline, char delim)
{
    std::stringstream ss(inputline);
    std::string dateBuffer;
    float valueBuffer(0);
    const char *headLine("date");
    std::pair<Entry, bool> returnVal(std::make_pair("", float(0)), false);

    if (!std::getline(ss, dateBuffer, delim).good())
    {
        if (!std::string(dateBuffer).find(delim) || ss.eof())
        {
            std::cerr << "Error: bad input => " << inputline << std::endl;
        }
    }

    // if it is the headline(date[','/'|']value)
    if (!dateBuffer.find(headLine, 0, 4))
    {
        // return a pair with an empty Entry and a boolean evaluated to false
        return returnVal;
    }

    if (ss.eof())
    {
        // return a pair with an empty Entry and a boolean evaluated to false
        return returnVal;
    }

    ss >> valueBuffer;

    returnVal.first.first = dateBuffer;
    returnVal.first.second = valueBuffer;
    returnVal.second = true;

    return returnVal;
}

bool BitcoinExchange::validate(const std::string date, const float value)
{
    if (!dateIsValid(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (value >= static_cast<float>(1000))
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

void BitcoinExchange::compute(const Entry& entry)
{
    const std::string inputDate(entry.first);
    const float inputValue(entry.second);
    Database::iterator itr(_exchangeRateMap.find(entry.first));

    if (itr == _exchangeRateMap.end()) // entry does not exist
    {
        // Inserting new element and finding previous value
        std::pair<Database::iterator, bool> newElem = _exchangeRateMap.insert(Entry(inputDate, 0));
        const bool was_inserted = newElem.second;
        itr = newElem.first;
        
        if (was_inserted)
        {
            // if there is a previous element (i.e. older date)
            if (itr != _exchangeRateMap.begin())
            {
                // copy previous element value to new one through a reference
                float& newValue = itr->second;
                newValue = (--itr)->second;
            }
        }
    }

    float result = itr->second * inputValue;

    std::cout << entry.first << " => ";
    std::cout << entry.second << " = ";
    std::cout << result << std::endl;
}


bool BitcoinExchange::dateIsValid(const std::string date)
{

    bool valid = true;
    std::stringstream ss;

    if (date.empty() || date.size() != 10u) // <----- Needs attention [!]
    {
        return false;
    }

    std::string s_year = date.substr(0u, 4u);
    std::string s_month =  date.substr(5u, 2u);
    std::string s_day = date.substr(8u, 2u);

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
    if (valid && month == 2u) // February
    {
        valid = (year % 4u == 0u) ? (day <=29u) : (day <= 28u); // checking leap years, because yes
    }
    else if (valid && month <= 7) // January - July
    {
        valid = ((month % 2) == 0) ? (day <= 30u) : (day <= 31u);
    }
    else if (valid) // August - December
    {
        valid = ((month % 2) == 0) ? (day <= 31u) : (day <= 30u);
    }

    return valid;
}

/**
 * Auxiliary functions
 */
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
    char buffer[50] = {0};
    BitcoinExchange btcEx;

    inputFile.open(path);
    inputFile.exceptions(std::istream::badbit);

    if (inputFile.is_open())
    {
            while (inputFile.getline(buffer, 50u).good())
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
