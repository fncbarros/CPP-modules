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

BitcoinExchange::BitcoinExchange()
{
    std::ifstream inputFile("./input-files/data.csv");
    char dateBuffer[MAXLINE];
    float rateBuffer;

    _fileIsValid = inputFile.is_open();
    inputFile.ignore(MAXLINE, '\n');
    if (_fileIsValid)
    {
        while (inputFile.getline(dateBuffer, MAXLINE, ',').good())
        {
            inputFile >> rateBuffer;
            // TODO: value is defaulting to 0 on all elements
            _exchangeRateMap.insert(std::make_pair(dateBuffer, rateBuffer));
        }
        inputFile >> rateBuffer;
        _exchangeRateMap.insert(std::make_pair(std::string(dateBuffer), rateBuffer));

        _fileIsValid = (!inputFile.bad());
    }
    inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {

    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::checkFile()
{
    return _fileIsValid;
}
