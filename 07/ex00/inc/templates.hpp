/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:28:23 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/05 09:28:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
#define TEMPLATES_H

template <typename T>
void    swap(T& a, T& b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T    min(const T& a, const T& b) {
    return a < b ? a : b;
}

template<typename T>
T   max(const T& a, const T& b) {
    return a > b ? a : b;
}

#endif //TEMPLATES_H
