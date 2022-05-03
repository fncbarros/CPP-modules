/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:14 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/03 18:07:48 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	// cout << "Phonebook: Constructor called.\n";
	index = 0;
	size = 0;
} ;

Phonebook::~Phonebook(void) {
	// cout << "Phonebook: Destructor called.\n";
} ;

class Contact	Phonebook::getContact(int i) {
	return (list[i]);
};

void			Phonebook::addContact(void) {

	list[index].add();
	if (index == 7)
		index = 0;
	else
		index++;
	if (size < 8)
		size++;
};

void	Phonebook::options(void) {
	int	i;
	string	input;
	stringstream	ss;

	if (size == 0) {
		cout << "No Contacts available.\n";
		return ;
	}
	cout << setfill(' ') << setw(10);
	cout << "index" << "|" ;
	cout << setfill(' ') << setw(10);
	cout << "Name" << "|" ;
	cout << setfill(' ') << setw(10);
	cout << "Surname" << "|" ;
	cout << setfill(' ') << setw(10);
	cout << "Nickname" << "|\n";
	for (int i = 0; i < int(size); i++) {
		list[i].printInfo(i);
	}
	i = 0;
	while (i < 1 || i > int(size)) {
	cout << "\nPlease specify contact index: ";
	getline(cin, input);
	ss << input;
	ss >> i;
	if (i > int(size) || i < 0) {
		cout << "No such contact.\n";
		ss.clear();
	}
	}
	ss.clear();
	list[i - 1].show();
} ;