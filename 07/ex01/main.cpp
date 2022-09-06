/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:30:51 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/05 09:30:53 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void    printArr(T  *array, size_t len) {
    std::cout << "{" << array[0];
    for (size_t i = 1; i < len; i++) {
        std::cout << ", ";
        std::cout << array[i];
    }
    std::cout << "}\n";
}

void    f1(int& i) {
    i++;
}

void    f2(char& c) {
    if (c >= 'a' && c <= 'z')
        c -= 'a' - 'A';
}

void    f3(bool& b) {
    b = (b == true) ? false : true;
}

template<typename T>
void    f4(T& t) {
    t += 42;
}

int main()
{
    int  i_arr[] = {1, 2, 3, 4, 5};
    char c_arr[] = "String";
    bool b_arr[] = {1, 0, 1, 1};

    std::cout << "Initial values i_arr:\n";
    printArr(i_arr, 5);
    iter(i_arr, 5, &f1);
    printArr(i_arr, 5);
    std::cout << "Initial values c_arr:\n";
    printArr(c_arr, 6);
    iter(c_arr, 7, f2);
    printArr(c_arr, 6);
    std::cout << "Initial values b_arr:\n";
    printArr(b_arr, 4);
    iter(b_arr, 4, f3);
    printArr(b_arr, 4);

    iter(i_arr, 5, f4);
    iter(c_arr, 6, f4);
    printArr(i_arr, 5);
    printArr(c_arr, 6);
}
