/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:49:32 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/29 18:47:24 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/



int main(void)
{
	string		input;
	Phonebook	Phonebook;
	static int	j, k;
	// stringstream ss;

	cout << "type ADD, SEARCH or EXIT:" << endl;
	while (input != "EXIT") {
		getline(cin, input); // gets full line from stdin
		//std::cin >> in;
		if (input == "ADD") {
			Phonebook.addContact();
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
