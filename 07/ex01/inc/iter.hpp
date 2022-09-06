/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:30:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/05 09:31:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T>
void    iter(T *array, size_t length, void (*func)(T& element)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif // ITER_H
