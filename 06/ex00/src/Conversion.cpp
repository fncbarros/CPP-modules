/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:40:50 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/21 13:40:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(const std::string& str) :
literal(str)
{
    setType();
    setValue();
}

Conversion::Conversion(const Conversion& other) {

    *this = other;

}

Conversion& Conversion::operator=(const Conversion& other) {
	if (this != &other)
	{
        literal = other.literal;
        setType();
        setValue();
	}
	return *this;
}

Conversion::~Conversion() {
}

void    Conversion::printChar() const {
    unsigned char value;

    std::cout << "char: ";
    switch (original.type) {
        case 0:
            (void)value;
            std::cout << original.value.c << std::endl;
            return;
        case 1:
            value = static_cast<unsigned char>(original.value.i);
            break;
        case 2:
            value = static_cast<unsigned char>(original.value.f);
            break;
        case 3:
            value = static_cast<unsigned char>(original.value.d);
            break;
        case 4:
            std::cout << "impossible" << std::endl;
            return;
    }
    if (value < 32 || value == 127)
        std::cout << "Non displayable\n";
    else if (value > 127)
        std::cout << "impossible\n";
    else
        std::cout << value << std::endl;
}

void    Conversion::printInt() const {
    int i = 0;
    std::cout << "int: ";

    switch (original.type) {
        case 0:
            std::cout << static_cast<int>(original.value.c) << std::endl;
            return;
        case 1:
            std::cout << original.value.i << std::endl;
            break;
        case 2:
            i = static_cast<int>(original.value.f);
            if (i != static_cast<long long>(original.value.f)) {
                std::cout << "impossible\n";
                return ;
            }
            std::cout << i << std::endl;
            break;
        case 3:
            i = static_cast<int>(original.value.d);
            if (i != static_cast<long long>(original.value.d)) {
                std::cout << "impossible\n";
                return ;
            }
            std::cout << i << std::endl;
            break ;
        case 4:
            std::cout << "impossible" << std::endl;
    }
}

void    Conversion::printFloat() const {
    float fvalue;

    std::cout << "float: ";
    switch (original.type) {
        case 0:
            fvalue = static_cast<float>(original.value.c);
            break;
        case 1:
            fvalue = static_cast<float>(original.value.i);
            break;
        case 2:
            fvalue = original.value.f;
            break;
        case 3:
            fvalue = static_cast<float>(original.value.d);
            break;
        case 4:
            std::cout << literal << "f\n";
            return;
    }
    std::cout << std::fixed << std::setprecision(1) << fvalue;
    std::cout << "f\n";
}

void    Conversion::printDouble() const {
    double dvalue;

    std::cout << "double: ";
    switch (original.type) {
        case 0:
            dvalue = static_cast<double>(original.value.c);
            break;
        case 1:
            dvalue = static_cast<double>(original.value.i);
            break;
        case 2:
            dvalue = static_cast<double>(original.value.f);
            break;
        case 3:
            dvalue = original.value.d;
            break;
        case 4:
            std::cout << literal << std::endl;
            return;
    }
    std::cout << dvalue;
}

bool    Conversion::isChar() {
    if (literal.length() == 1) {
        return !std::isdigit(literal[0]);
    }
    return false;
}

bool    Conversion::isInt() {
    std::string::size_type pos = 0;


    if (literal.length() > 1) {
        if (literal[0] == '-' || literal[0] == '+')
            pos++;
        else if (literal[0] == '.')
            return false;
        while (pos < literal.size()) {
            if (!std::isdigit(literal[pos]))
                return false;
            pos++;
        }
    }
    else if (!std::isdigit(literal[0]))
        throw FailedToConvert();
    return true;
}

bool    Conversion::isPseudo() {
    if (!literal.compare(1, 3, "inf")) {
        if (literal.length() > 5 || (literal.length() == 5 && literal[4] != 'f')
                || (literal[0] != '-' && literal[0] != '+')) {
            throw FailedToConvert();
        }
        literal = literal.substr(0, 4);
        return true;
    }
    else if (!literal.compare(0, 3, "nan")) {
        if (literal.length() > 4 || (literal.length() == 4 && literal[3] != 'f')) {
            throw FailedToConvert();
        }
        literal = literal.substr(0, 3);
        return true;
    }
    return false;
}

bool    Conversion::isDouble() {
    size_t  pos = literal.find('.');
    size_t  i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0 ;

    while (i < pos) {
        if (i > 0 && !std::isdigit(literal[i]))
            throw FailedToConvert();
        i++;
    }
    if (i == 0 || (i == 1 && pos < 3) || pos == literal.size() - 1)
        throw FailedToConvert();
    while (++pos < literal.size()) {
        if (!std::isdigit(literal[pos])) {
            if (literal[pos] != 'f')
                throw FailedToConvert();
            else if (literal[pos - 1] == '.')
                throw FailedToConvert();
            return false;
        }
    }
    return true;
}

bool    Conversion::isFloat() {
    size_t pos = literal.find('f', 1);

    if (pos == std::string::npos || pos != literal.length() - 1) {
        return false;
    }
    return true;
}

void    Conversion::setType() {
    if (isChar()) {
        original.type = s_conversion::CHAR;
        return ;
    }
    else if (isInt()) {
        original.type = s_conversion::INT;
        return ;
    }
    else if (isPseudo()) {
        original.type = s_conversion::PSEUDO;
        return ;
    }
    else if (literal.find('.') != std::string::npos) {
        if (isDouble()) {
            original.type = s_conversion::DOUBLE;
            return ;
        } 
        else if (isFloat()) {
            original.type = s_conversion::FLOAT;
            return ;
        }
    }
    throw FailedToConvert();
}

void    Conversion::setValue() {
    long int n = 0;
    double d = 0;
    std::stringstream ss(literal);

    switch (original.type) {
        case 0:
            ss >> original.value.c;
            break ;
        case 1:
            ss >> n;
            if (n > INT_MAX || n < INT_MIN)
                throw FailedToConvert();
            original.value.i = static_cast<int>(n);
            break ;
        case 2:
            d = std::strtod(literal.c_str(), NULL);
            original.value.f = float(d);
            break ;
        case 3:
            d = std::strtod(literal.c_str(), NULL);
            d = std::strtod(literal.c_str(), NULL);
            original.value.d = std::strtod(literal.c_str(), NULL);
        case 4:
            break ;
    }
}
