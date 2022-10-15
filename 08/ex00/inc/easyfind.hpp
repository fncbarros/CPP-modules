/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:24:20 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 15:24:23 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
typename T::const_iterator    easyfind(const T& a, const int b) {
    return std::find(a.begin(), a.end(), b);
}
