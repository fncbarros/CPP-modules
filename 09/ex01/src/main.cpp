/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:14:26 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/08 11:14:28 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: No sufficient arguments" << std::endl;
        return 1;
    }

    std::stringstream ss;

    for (int i = 1; i < argc; i++ )
    {
        ss << std::string(argv[i]);
    }

    RPN rpn;

    if (rpn.setStack(ss))
    {
        // std::cout << rpn.getResult() << std::endl;
        return 0;
    }

    return 1;
}