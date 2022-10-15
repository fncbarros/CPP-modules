/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:44:37 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 15:44:39 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : V() {

}

Span::Span(const unsigned int N) :
N(N),
V(N) {
}

Span::Span(const Span& other) :
N(N),
V(other.V) {
}

Span Span::operator=(const Span& other) {
    if (this != &other)
    {
        size_t i = 0; // tmp
        for (std::vector<int>::const_iterator it = other.V.begin(); it != other.V.end(); it++)
            V[i] = *it;
    }
    return *this;
}

Span::~Span() {

}

void    Span::addNumber(int number) {
    if (number < N)
    {
        V.push_back(number);
    }
}

int    Span::shortestSpan() {
    if (V.size() < 2)
        throw noSpanFound();
}

int    Span::longestSpan() {
    if (V.size() < 2)
        throw noSpanFound();
}
