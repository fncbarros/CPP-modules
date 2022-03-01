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

#include "Phonebook.hpp"

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/



int main(void)
{
	string	input;
	Phonebook	Phonebook;
	static int	i, j, k;
//	stringstream ss;

	cout << "ADD, SEARCH or EXIT" << endl;
	while (input != "EXIT") {
		getline(cin, input); // gets full line from stdin
		//std::cin >> in;
		if (input == "ADD") {
			Phonebook.getContact(i++).add();
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH") {
			j = 0;
			while (Phonebook.getContact(j).options(j))	{
				j++;
			}
			if (!j) {
				cout << "No Contacts available." << endl;
				continue ;
			}
			cout << "Please specify contact index: ";
			getline(cin, input);
			stringstream ss(input);
			ss >> k;
			if (k < 1 || k > j)
				cout << "Contact does not exist." << endl;
			else
				Phonebook.getContact(k - 1).show();
				// Phonebook.list[k - 1].show();
		}
	}
	return (0);
}

