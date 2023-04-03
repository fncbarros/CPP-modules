/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:51:41 by fbarros           #+#    #+#             */
/*   Updated: 2023/03/06 19:51:42 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <algorithm>
#include <map>
#include <sstream>


static const unsigned short MAXLINE = 50;

class BitcoinExchange {
public:
    typedef std::map<std::string, float> Database;
    typedef std::pair<std::string, float> Entry;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // std::pair<std::string, float> readLine(const std::string& inputline, char delim);
    std::pair<Entry, bool> readLine(const std::string& inputline, char delim);
    
    bool validate(const std::string date, const float value);

private:
    Database readFile(std::string path, char delim);
    bool validDate(const std::string date);

private:
    Database _exchangeRateMap;

};

void printDatabase(const BitcoinExchange::Database& database);
void printDatabase(const char *path);
