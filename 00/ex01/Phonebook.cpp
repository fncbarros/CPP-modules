/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:14 by fbarros           #+#    #+#             */
/*   Updated: 2022/03/07 18:25:06 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	// cout << "Constructor called." << endl;
	index = 0;
	//class Contact::Contact	list[8]; // ??
} ;

Phonebook::~Phonebook(void) {
	// cout << "Destructor called." << endl;
} ;

class Contact	Phonebook::getContact(int index) {
	return (list[index]);
};

void			Phonebook::add(void) {
//	exists = true;
	cout << "Name:" <<endl;
	getline(cin, list[index].getName());
//	cin >> Name;
	cout << "Surname:" <<endl;
	getline(cin, list[index].getSurname());
//	cin >> Surname;
	cout << "Nickname:" <<endl;
	getline(cin, list[index].getNickname());
//	cin >> Nickname;
	cout << "Number:" <<endl;
	getline(cin, list[index].getNumber());
//	cin >> Number;
	cout << "Secret:" <<endl;
	getline(cin, list[index].getSecret());
//	cin >> Secret;
	if (index == 8)
		index = 0;
	else
		index++;
};