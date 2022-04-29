/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:14 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/29 20:40:22 by fbarros          ###   ########.fr       */
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

class Contact	Phonebook::getContact(int i) {
	return (list[i]);
};

void			Phonebook::addContact(void) {
	list[index].add();
	if (index == 8)
		index = 0;
	else
		index++;
};
