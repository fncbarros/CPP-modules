/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:10:18 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/09 17:22:07 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iomanip>


int main(int argc, char *argv[])
{
    if (argc == 2) {
        Harl harl;
        harl.complain(argv[1]);
    }
    else {
        cout << "Usage: ./Harl2 <place_complaint>\n";
        cout << "Options: \n\tDEBUG\n\tINFO\n\tWARNING\n\tERROR\n";
        return 1;
    }

    return 0;
}