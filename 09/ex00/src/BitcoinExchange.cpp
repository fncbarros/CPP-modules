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

BitcoinExchange::BitcoinExchange()
{
    std::ifstream inputFile("./input-files/data.csv");
    char dateBuffer[MAXLINE] = {0};
    float rateBuffer;

    inputFile.exceptions(std::istream::badbit);
    if (!inputFile.is_open())
    {
        return ;
    }
    inputFile.ignore(MAXLINE, '\n');

    try {
        while (inputFile.getline(dateBuffer, MAXLINE, ',').good())
        {
            inputFile >> rateBuffer;
            // TODO: value is defaulting to 0 on all elements
            _exchangeRateMap.insert(std::make_pair(dateBuffer, rateBuffer));
        }
        inputFile >> rateBuffer;
        _exchangeRateMap.insert(std::make_pair(std::string(dateBuffer), rateBuffer));

        for (std::map<std::string, float>::iterator it = _exchangeRateMap.begin();
                it != _exchangeRateMap.end(); 
                it++)
        {
            std::cout << it->first << " " << it->second;
        }

    } catch (const std::exception& e)
    {
        std::cerr << "Error: could not open file.\n";
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
