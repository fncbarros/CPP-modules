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

typedef std::map<std::string, float> Database;

static const u_int8_t MAXLINE = 50;

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    Database readFile(std::string path, char delim);

private:
    std::string _inputBuffer;
    Database _exchangeRateMap;
};

void printDatabase(const Database& database);
