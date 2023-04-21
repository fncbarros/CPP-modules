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

bool checkIfEmpty(std::ifstream& file)
{
	// Checking if file is empty
	file.get();
	if (file.eof())
	{
		std::cerr << "Error: file is empty.\n";
		return true;
	}
	else
	{
		file.unget();
		return false;
	}
}

int main(int argc, char *argv[])
{
	BitcoinExchange btcEx;
	std::ifstream inputFile;
	std::string inputBuffer;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	inputFile.open(argv[1]);

	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}

	if (checkIfEmpty(inputFile))
	{
		return 1;
	}

	while (std::getline(inputFile, inputBuffer))
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
}
