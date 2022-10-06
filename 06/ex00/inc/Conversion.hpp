/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:41:07 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/21 13:41:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <exception>
#include <limits.h>
#include <limits>

class Conversion {
public:
	Conversion(const std::string& str);
    Conversion(const Conversion& other);
	Conversion& operator=(const Conversion& other);
	~Conversion();

    void    printChar() const;
    void    printInt() const;
    void    printFloat() const;
    void    printDouble() const;

private:
    std::string literal;
    struct s_conversion 
    {
        enum e_type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO
        }   type;

        union u_value{
            char    c;
            int     i;
            float   f;
            double  d;
        }   value;

    }   original;

    bool    isPseudo();
    bool    isFloat();
    bool    isDouble();
    bool    isChar();
    bool    isInt();
    void    setType();
    void    setValue();

    class FailedToConvert : public std::exception {
        const char *what() const throw() {
            return "Failed to convert string";
        }
    };
};

#endif /* CONVERSION_HPP */
