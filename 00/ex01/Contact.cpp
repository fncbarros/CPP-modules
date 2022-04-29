/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/29 20:59:21 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	cout << "Constructor called." << endl;
	exists = false;
} ;

Contact::~Contact(void) {
	cout << "Destructor called." << endl;
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
	// or this->Name = _Name;
	// or ...setName(_Name) : Name(_Name)
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

void	Contact::add(void) {
	string	in;

	exists = true;
	cout << "Name:\n";
	getline(cin, in);
	setName(in);
	cout << "Surname:\n";
	getline(cin, in);
	setSurname(in);
	cout << "Nickname:\n";
	getline(cin, in);
	setNickname(in);
	cout << "Number:\n";
	getline(cin, in);
	setNumber(in);
	cout << "Secret:\n";
	getline(cin, in);
	setSecret(in);
} ;


/* Any output longer than the columns’ width is truncated and the
last displayable character is replaced by a dot (’.’).*/
bool	Contact::options(int index) {
	if (!exists)
		return (false);
	
	cout << setfill(' ') << setw(10);
	cout << index + 1 << "|" ;
	cout << setfill(' ') << setw(10);
	Name.length() > 10 ? cout << Name.substr(0, 9) + "." << "|" :
	cout << Name << "|" ;
	cout << setfill(' ') << setw(10);
	Surname.length() > 10 ? cout << Surname.substr(0, 9) + "." << "|" :
	cout << Surname << "|" ;
	cout << setfill(' ') << setw(10);
	Nickname.length() > 10 ? cout << Nickname.substr(0, 9) + "." << "|" :
	cout << Nickname << "|";
	cout << endl;
	return (true);
} ;

void	Contact::show(void) {
	cout << "Name: " << Name << endl;
	cout << "Surname: " << Surname << endl;
	cout << "Nickname: " << Nickname << endl;
	cout << "Number: " << Number << endl;
	cout << "Secret: " << Secret << endl;
} ;
