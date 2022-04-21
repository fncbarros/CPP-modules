/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:14 by fbarros           #+#    #+#             */
/*   Updated: 2022/03/08 16:44:22 by fbarros          ###   ########.fr       */
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
	Contact	newContact;
	
	list[index] = newContact.add();
	if (index == 8)
		index = 0;
	else
		index++;
};