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

#include "phone.hpp"

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/

int main(void)
{
	std::string	in;
	Contact	PhoneBook[8];
	static int	i;

	std::cout << "ADD, SEARCH or EXIT" << std::endl;
	while (in != "EXIT" && in != "SEARCH" && in != "ADD")
		std::cin >> in;
	if (in == "EXIT")
		return (0);
	else if (in == "ADD")
	{
		PhoneBook[i].add();
	}
	else if (in == "SEARCH")
	{

	}
}
