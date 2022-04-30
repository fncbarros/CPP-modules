/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:49:32 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/30 20:16:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*PhoneBook must be represented as an instance of a class(Contact)
 * must contain an array of contacts*/



int main(void)
{
	string		input;
	Phonebook	Phonebook;

	while (input != "EXIT") {
		cout << "\nType ADD, SEARCH or EXIT:\n";
		getline(cin, input);
		if (input == "ADD") {
			Phonebook.addContact();
		}
		else if (input == "SEARCH") {
			Phonebook.options();
		}
	}
	return (0);
}
