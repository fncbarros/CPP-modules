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

/**
 * TODO: Error handling, check if outside limits
 * */

Conversion::Conversion(const std::string& str) :
literal(str)
{
    setType();
    setValue();
}

Conversion::Conversion(const Conversion& other) {
	if (this != &other)
	{
		*this = other;
	}
}

Conversion& Conversion::operator=(const Conversion& other) {
	if (this != &other)
	{
        literal = other.literal;
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
            value = (unsigned char)original.value.i;
            break;
        case 2:
            value = (unsigned char)original.value.f;
            break;
        case 3:
            value = (unsigned char)original.value.d;
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
    std::cout << "int: ";
    switch (original.type) {
        case 0:
            std::cout << int(original.value.c) << std::endl;
            return;
        case 1:
            std::cout << original.value.i << std::endl;
            break;
        case 2:
            std::cout << int(original.value.f) << std::endl;
            break;
        case 3:
            std::cout << int(original.value.d) << std::endl;
            break;
        case 4:
            std::cout << "impossible" << std::endl;
            return;
    }
}

void    Conversion::printFloat() const {
    float fvalue;
    int   ivalue;

    std::cout << "float: ";
    switch (original.type) {
        case 0:
            fvalue = float(original.value.c);
            break;
        case 1:
            fvalue = float(original.value.i);
            break;
        case 2:
            fvalue = original.value.f;
            break;
        case 3:
            fvalue = float(original.value.d);
            break;
        case 4:
            std::cout << literal << "f\n";
            return;
    }
    std::cout << fvalue;
    ivalue = int(fvalue);
    if (fvalue - ivalue == 0)
        std::cout << ".0";
    std::cout << "f\n";
}

void    Conversion::printDouble() const {
    float fvalue;
    int   ivalue;

    std::cout << "double: ";
    switch (original.type) {
        case 0:
            fvalue = double(original.value.c);
            break;
        case 1:
            fvalue = double(original.value.i);
            break;
        case 2:
            fvalue = double(original.value.f);
            break;
        case 3:
            fvalue = original.value.d;
            break;
        case 4:
            std::cout << literal << std::endl;
            return;
    }
    std::cout << fvalue;
    ivalue = int(fvalue);
    if (fvalue - ivalue == 0)
        std::cout << ".0\n";
}

void    Conversion::setType() {
    if (literal.length() > 1) {
        if (!literal.compare(1, 3, "inf")) {
            literal = literal.substr(0, 4);
            original.type = s_conversion::PSEUDO;
            return ;
        }
        else if (!literal.compare(0, 3, "nan")) {
            literal = literal.substr(0, 3);
            original.type = s_conversion::PSEUDO;
            return ;
        }
        else if (literal.find('.') != std::string::npos) {
            if (literal.find('f', 1) != std::string::npos)
                original.type = s_conversion::FLOAT;
            else
                original.type = s_conversion::DOUBLE;
            return ;
        }
    }
    else if (literal.c_str()[0] < '0' || literal.c_str()[0] > '9') {
        original.type = s_conversion::CHAR;
        return ;
    }
    original.type = s_conversion::INT;
}

void    Conversion::setValue() {
    std::stringstream ss(literal);

    switch (original.type) {
        case 0:
            ss >> original.value.c;
            break ;
        case 1:
            ss >> original.value.i;
            break ;
        case 2:
            ss >> original.value.f;
            break ;
        case 3:
            ss >> original.value.d;
        case 4:
            break ;
    }
}
