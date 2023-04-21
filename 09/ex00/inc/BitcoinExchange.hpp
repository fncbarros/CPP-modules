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

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange {
public:
    typedef std::map<std::string, float> Database;
    typedef std::pair<std::string, float> Entry;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    std::pair<Entry, bool> readLine(const std::string& inputline, char delim);
    bool validate(const std::string date, const float value);
    void compute(const Entry& entry);

private:
    Database readCSVFile(const char *path, const char delim);
    bool dateIsValid(const std::string date);

private:
    Database _exchangeRateMap;

};

/**
 * Auxiliary functions
 */
void printDatabase(const BitcoinExchange::Database& database);
void printDatabase(const char *path);

#endif
