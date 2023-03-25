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

static const u_int8_t MAXLINE = 30;

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool checkFile();

private:
    // TODO: remove boolean and create exception instead
    bool _fileIsValid;
    std::string _inputBuffer;
    std::map<std::string, float> _exchangeRateMap;
};
