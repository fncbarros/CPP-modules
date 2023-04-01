/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:50:02 by fbarros           #+#    #+#             */
/*   Updated: 2023/03/06 19:50:24 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[2])
{
	BitcoinExchange btcEx;
	(void)argv;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	std::ifstream inputFile(argv[1]);
    char buffer[MAXLINE] = {0};
    BitcoinExchange::Database mapBuffer;

    // TODO: not handling wrong file name
    inputFile.exceptions(std::istream::badbit);

    if (inputFile.is_open())
    {
            while (inputFile.getline(buffer, MAXLINE).good())
            {
                BitcoinExchange::Entry element = btcEx.readLine(buffer, '|');
                if (element.first != "")
                {
					std::cout << element.first << " " << element.second << std::endl;
				}
			}
	}
}
