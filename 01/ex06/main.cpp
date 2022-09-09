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
        // Harl harl;


        switch (int(*argv[1]))
        {
        case 'D':
            cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
        case 'I':
            cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
        case 'W':
            cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
        case 'E':
	        cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
            break;
        default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
        }


    } else {
        cout << "Usage: ./Harl2 <place_complaint>\n";
        cout << "Options: \n\tDEBUG\n\tINFO\n\tWARNING\n\tERROR\n";
    }

    return 0;
}