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

#include "Contact.hpp"

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/

int main(void)
{
	string	input;
	Contact	PhoneBook[8];
	static int	i;

	cout << "ADD, SEARCH or EXIT" << endl;
	while (input != "EXIT")
	{
		getline(cin, input); // gets full line from stdin
		//std::cin >> in;
		if (input == "ADD")
		{
			PhoneBook[i++].add();
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH")
		{
			for (int j = 0; j < 8; j++)
				PhoneBook[j].options(j);
			// prompt for index
			// display contact info (If the input makes no
			// sense, define a relevant behavior.)
			i = 0;
			while (!i)
			{
				cout << "Please specify contact index: ";
				cin >> i;
				if (i > 8 || !PhoneBook[i - 1].show())
				{
					cout << endl << "Contact unavailable" << endl;
					i = 0;
				}
			}
		}
	}
	// call destructor ?
	return (0);
}
