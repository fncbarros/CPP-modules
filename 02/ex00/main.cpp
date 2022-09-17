/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:44 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/13 12:45:17 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

namespace subjectTest
{
   void run()
    {
        Fixed a;
        Fixed b( a );
        Fixed c;

        c = b;

        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }

} // namespace noValue

namespace myTest
{
    void run()
    {
        Fixed a;
        a.setRawBits(42);
        Fixed b( a );
        Fixed c;

        c = b;

        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }

} // namespace Value


int main()
{
    subjectTest::run();
    myTest::run();

    return 0;
}