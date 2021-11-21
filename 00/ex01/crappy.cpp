/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crappy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:49:32 by fbarros           #+#    #+#             */
/*   Updated: 2021/11/21 14:57:04 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/

class	Contact{
	public:
		std::string	Name;
		std::string Surname;
		std::string Nickname;
		std::string	Number;
		std::string	Secret;
};

int main(void)
{
	std::string	in;
	Contact	PhoneBook[8];

	std::cout << "ADD, SEARCH or EXIT" << std::endl;
	while (in != "EXIT" && in != "SEARCH" && in != "ADD")
		std::cin >> in;
	if (in == "EXIT")
	{
		std::cout << "Phonebook destroyed" << std::endl;
		return (0);
	}
	else if (in == "ADD")
	{
		// call constructor ??
	}
	else if (in == "SEARCH")
	{

	}
}
