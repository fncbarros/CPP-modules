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
    char buffer[30];

    _fileCheck = inputFile.is_open();
    if (_fileCheck)
    {
        while (inputFile.getline(buffer, 30, ',').good())
        {
        }
        _fileCheck = (!inputFile.bad());
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
    return _fileCheck;
}
