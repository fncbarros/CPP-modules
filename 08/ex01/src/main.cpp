/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:25:24 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 15:25:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    try {
        sp.longestSpan();
    } catch (const std::exception& e) { std::cout << e.what() << std::endl;}
    try {
        sp.shortestSpan();
    } catch (const std::exception& e) { std::cout << e.what() << std::endl;}    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) { std::cout << e.what() << std::endl;}

    {
        Span sp2(2);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(12);
        std::cout << sp2.longestSpan() << std::endl;

        sp2 = sp;
        std::cout << sp2.longestSpan() << std::endl;
    }

    return 0;
}

