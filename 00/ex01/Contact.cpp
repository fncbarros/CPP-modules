/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/30 20:01:47 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	// cout << "Contact: Constructor called.\n";
	exists = false;
} ;

Contact::~Contact(void) {
	// cout << "Contact: Destructor called.\n";
} ;

string	Contact::getName(void) {
	return (Name);
} ;

string	Contact::getSurname(void) {
	return (Surname);
} ;

string	Contact::getNickname(void) {
	return (Nickname);
} ;

string	Contact::getNumber(void) {
	return (Number);
} ;

string	Contact::getSecret(void) {
	return (Secret);
} ;

void	Contact::setName(string _Name) {
	
	Name = _Name;
} ;

void	Contact::setSurname(string _Surname) {
	Surname = _Surname;
} ;

void	Contact::setNickname(string _Nickname) {
	Nickname = _Nickname;
} ;

void	Contact::setNumber(string _Number) {
	Number = _Number;
} ;

void	Contact::setSecret(string _Secret) {
	Secret = _Secret;
} ;

string	Contact::getNum(string prompt) {
	string	input;

	cout << prompt;
	while (input.empty()) {
		getline(cin, input);
		for (int i = 0; input[i]; i++) {
			if (!std::isdigit(input[i])) {
				cout << prompt;
				input.clear();
				break ;
			}
		}
	}
	return (input);
} ;

string	Contact::getAlpha(string prompt) {
	string	input;

	cout << prompt;
	while (input.empty()) {
		getline(cin, input);
		for (int i = 0; input[i]; i++) {
			if (!std::isalpha(input[i])) {
				cout << prompt;
				input.clear();
				break ;
			}
		}
	}
	return (input);
} ;

void	Contact::add(void) {
	setName(getAlpha("Name:\n"));
	setSurname(getAlpha("Surname:\n"));
	setNickname(getAlpha("Nickname:\n"));
	setNumber(getNum("Number:\n"));
	setSecret(getAlpha("Secret:\n"));
	exists = true;
} ;


/* Any output longer than the columns’ width is truncated and the
last displayable character is replaced by a dot (’.’).*/
void	Contact::printInfo(int index) {
	if (!exists)
		return ;

	cout << setfill(' ') << setw(10);
	cout << index + 1 << "|" ;
	cout << setfill(' ') << setw(10);
	Name.length() > 10 ? cout << Name.substr(0, 9) + "." << "|" : \
	cout << Name << "|" ;
	cout << setfill(' ') << setw(10);
	Surname.length() > 10 ? cout << Surname.substr(0, 9) + "." << "|" : \
	cout << Surname << "|" ;
	cout << setfill(' ') << setw(10);
	Nickname.length() > 10 ? cout << Nickname.substr(0, 9) + "." << "|" : \
	cout << Nickname << "|";
	cout << endl;
} ;

void	Contact::show(void) {
	cout << "\nName: " << Name << endl;
	cout << "Surname: " << Surname << endl;
	cout << "Nickname: " << Nickname << endl;
	cout << "Number: " << Number << endl;
	cout << "Secret: " << Secret << endl;
} ;
