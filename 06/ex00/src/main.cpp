/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:50:12 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/16 21:50:14 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        Conversion  arg(argv[1]);
        arg.printChar();
        arg.printInt();
        arg.printFloat();
        arg.printDouble();
    }
	return (0);
}
