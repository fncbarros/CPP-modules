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

int main(int argc, char *argv[])
{
	BitcoinExchange btcEx;
	std::ifstream inputFile;
	char inputBuffer[MAXLINE];
	// BitcoinExchange::Entry entry;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	try {
		inputFile.open(argv[1]);

		if (!inputFile.is_open())
		{
			std::cerr << "Error: could not open file.\n";
			return 1;
		}
		while (inputFile.getline(inputBuffer, MAXLINE))
		{
			std::pair<BitcoinExchange::Entry, bool> entry;
			
			entry = btcEx.readLine(inputBuffer, '|');
			if (entry.second == false)
			{
				continue ;
			}

			if (btcEx.validate(entry.first.first, entry.first.second))
			{
				btcEx.compute(entry.first);
			}
		}
	} catch (const std::exception& e) { std::cerr << e.what() << std::endl;}

}
