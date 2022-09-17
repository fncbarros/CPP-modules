/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:44 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/16 17:07:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

namespace comparison {
    void run() {
        std::cout << "**COMPARISON OPERATORS**\n\n";
        Fixed a(4.2f);
        Fixed b(7.5f);

        std::cout << "4.2 < 7.5: ";
        std::cout << (a < b ? "true" : "false") << std::endl;
        std::cout << "4.2 > 7.5: ";
        std::cout << (a > b ? "true" : "false") << std::endl;
        std::cout << "4.2 <= 7.5: ";
        std::cout << (a <= b ? "true" : "false") << std::endl;
        std::cout << "7.5 <= 7.5: ";
        std::cout << (b <= b ? "true" : "false") << std::endl;
        std::cout << "4.2 >= 7.5: ";
        std::cout << (a >= b ? "true" : "false") << std::endl;
        std::cout << "7.5 >= 7.5: ";
        std::cout << (b >= b ? "true" : "false") << std::endl;
        std::cout << "4.2 == 7.5: ";
        std::cout << (a == b ? "true" : "false") << std::endl;
        std::cout << "4.2 == 4.2: ";
        std::cout << (a == a ? "true" : "false") << std::endl;
        std::cout << "4.2 != 7.5: ";
        std::cout << (a != b ? "true" : "false") << std::endl;
        std::cout << "4.2 != 4.2: ";
        std::cout << (a != a ? "true" : "false") << std::endl;
    }
} // namespace comparison

namespace arithmetic {
    void run() {
        std::cout << "**ARITHMETIC OPERATORS**\n\n";
        Fixed a(4.2f);
        Fixed b(7.0f);

        std::cout << "a = " << a << "\nb = " << b <<std::endl;

        std::cout << "\na + b:\n";
        std::cout << a + b;
        std::cout << " (" << 4.2f + 7.0f << ")" << std::endl;

        std::cout << "b - a:\n";
        std::cout << b - a;
        std::cout << " (" << 7.0f - 4.2f << ")" << std::endl;

        std::cout << "a - b:\n";
        std::cout << a - b;
        std::cout << " (" << 4.2f - 7.0f << ")" << std::endl;

        std::cout << "a / b:\n";
        std::cout << a / b;
        std::cout << " (" << 4.2f / 7.0f << ")" << std::endl;

        std::cout << "b / a:\n";
        std::cout << b / a;
        std::cout << " (" << 7.0f / 4.2f << ")" << std::endl;

        std::cout << "a * b:\n";
        std::cout << a * b;
        std::cout << " (" << 4.2f * 7.0f << ")" << std::endl;
    }
} // namespace arithmetic

namespace increment {
    void run() {
        std::cout << "**INCREMENT/DECREMENT OPERATORS**\n\n";
        Fixed a;

        std::cout << "Increment:\n";
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        a.setRawBits(1 << 8);
        std::cout << "Decrement:\n";
        std::cout << a << std::endl;
        std::cout << --a << std::endl;
        std::cout << a << std::endl;
        std::cout << a--<< std::endl;
        std::cout << a << std::endl;
    }
} // namespace increment

namespace minmax {
    void run() {
        std::cout << "**MIN/MAX FUNCTIONS**\n\n";
        Fixed a(5.05f);
        Fixed const b( Fixed( a ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << "\nMax:\n";
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << "Min:\n";
        std::cout << Fixed::min( a, b ) << std::endl;
        Fixed const *pa = new const Fixed (2);
        const Fixed *pb = new const Fixed (2);
        std::cout << "\nSame number:\nmax(" << pa << ", " << pb << ")\n";
        std::cout << &Fixed::max( *pa, *pb ) << std::endl;
        std::cout << "min" << pa << ", " << pb << ")\n";
        std::cout << &Fixed::min( *pa, *pb ) << std::endl;
        delete pa; delete pb;
    }
} // namespace minmax

int main( void )
{
    comparison::run();
    arithmetic::run();
    increment::run();
    minmax::run();

    return 0;
}
