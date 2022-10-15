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
#include <vector>
#include <iterator>
#include <exception>

class Span {
public:
    Span();
    Span(const unsigned int N);
    Span(const Span& other);
    Span operator=(const Span& other);
    ~Span();

    void    addNumber(int number);
    int    shortestSpan();
    int    longestSpan();

private:
    unsigned int        N;
    std::vector<int>    V;

    class noSpanFound : public std::exception {
        const char  *what() const throw() {
            return "No span can be found.";
        }
    };
};
