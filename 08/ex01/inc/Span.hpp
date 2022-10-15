/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:24:33 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 15:26:05 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <set>
#include <iterator>
#include <exception>
#include <iostream>

class Span {
public:
    Span();
    Span(const unsigned int N);
    Span(const Span& other);
    Span operator=(const Span& other);
    ~Span();

    void    addNumber(int number);
    int    shortestSpan() const;
    int    longestSpan() const;

private:
    unsigned int        N;
    std::set<int>       S;

    class noSpanFound : public std::exception {
        const char  *what() const throw() {
            return "No span can be found.";
        }
    };
};
