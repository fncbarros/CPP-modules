/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:48:15 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 17:49:18 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stack>
#include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef std::stack<T, Container> Stack;
    using Stack::operator=;
    using Stack::c;
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

public:
    MutantStack() {}
    MutantStack(const MutantStack& other) { *this = other;}
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
        {
            this->operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    iterator begin( void ) { return c.begin();}
    iterator end( void ) { return c.end();}

    const_iterator begin(void) const { return c.begin();}
    const_iterator end(void) const { return c.end();}

    reverse_iterator rbegin(void) { return c.rbegin();}
    reverse_iterator rend(void) { return c.rend();}

    const_reverse_iterator rbegin(void) const { return c.rbegin();}
    const_reverse_iterator rend(void) const { return c.rend();}

private:

};
