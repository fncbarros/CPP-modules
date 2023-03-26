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

int main(int argc, char *argv[2])
{
	BitcoinExchange btcEx;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	Database inputFile(btcEx.readFile(std::string(argv[1]), '|'));
    printDatabase(inputFile);

	return 0;
}
