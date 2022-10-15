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

Span::Span() :
N(0)
{
}

Span::Span(const unsigned int N) :
N(N)
{
}

Span::Span(const Span& other) :
N(other.N),
S(other.S)
{
}

Span Span::operator=(const Span& other) {
    if (this != &other)
    {
        S.clear();
        S = other.S;
    }
    return *this;
}

Span::~Span() {

}

void    Span::addNumber(int number) {
    if (S.size() < N)
    {
        S.insert(number);
    } else {
        std::cout << "Container has reached maximum capacity.\n";
    }
}

int    Span::shortestSpan() const {
    int span = S.size();

    if (S.size() < 2)
        throw noSpanFound();
    for (std::set<int>::const_iterator it = S.begin(); it != S.end();) {
        int i = *it;
        if (++it != S.end())
            i = *it - i;
        span = span < i ? span : i;
    }
    return span;
}

int    Span::longestSpan() const {
    if (S.size() < 2)
        throw noSpanFound();
    return *S.rbegin() - *S.begin();
}
