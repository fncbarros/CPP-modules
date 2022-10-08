/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:32:29 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/06 22:32:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
public:
    Array() : array(0) { array = new T[0]();}
    Array(const unsigned int n) : array(0), n(n) { array = new T[n]();}
    Array(const Array& other) : array(0) {
            array = new T[other.n];
            for (this->n = 0; n < other.n; n++)
                array[n] = other.array[n]; 
    }
    Array&  operator=(const Array& other) {
        if (this != &other) {
            this->~Array();
            array = new T[other.n]();
            for (this->n = 0; n < other.n; n++)
                array[n] = other.array[n];
        }
        return *this;
    }
    ~Array() {
        if (array != NULL) 
            delete [] array;
        array = NULL;
        n = 0;
    }
    T&  operator[](int i) const {
        if (i < 0 || size_t(i) >= n)
            throw outOfBounds();
        return array[i];
    }
    size_t  size() const { return n; }

private:
    T   *array;
    size_t  n;

    class outOfBounds : public std::exception {
        const char *what() const throw() {
            return "index out of bounds.";
        }
    };
};

#endif // ARRAY_HPP
