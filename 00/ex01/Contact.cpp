/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/03/07 18:01:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	// cout << "Constructor called." << endl;
	exists = 0;
} ;

Contact::~Contact(void) {
	// cout << "Destructor called." << endl;
} ;

class Contact	getContact(void) {
	return ()
} ;

// void	Contact::add(void) {
// 	exists = true;
// 	cout << "Name:" <<endl;
// 	getline(cin, Name);
// //	cin >> Name;
// 	cout << "Surname:" <<endl;
// 	getline(cin, Surname);
// //	cin >> Surname;
// 	cout << "Nickname:" <<endl;
// 	getline(cin, Nickname);
// //	cin >> Nickname;
// 	cout << "Number:" <<endl;
// 	getline(cin, Number);
// //	cin >> Number;
// 	cout << "Secret:" <<endl;
// 	getline(cin, Secret);
// //	cin >> Secret;
// } ;


// /* Any output longer than the columns’ width is truncated and the
// last displayable character is replaced by a dot (’.’).*/
// bool	Contact::options(int index) {
// 	if (!exists)
// 		return (false);
// 	cout << setfill(' ') << setw(10);
// 	cout << index + 1 << "|" ;
// 	cout << setfill(' ') << setw(10);
// 	Name.length() > 10 ? cout << Name.substr(0, 9) + "." << "|" :
// 	cout << Name << "|" ;
// 	cout << setfill(' ') << setw(10);
// 	Surname.length() > 10 ? cout << Surname.substr(0, 9) + "." << "|" :
// 	cout << Surname << "|" ;
// 	cout << setfill(' ') << setw(10);
// 	Nickname.length() > 10 ? cout << Nickname.substr(0, 9) + "." << "|" :
// 	cout << Nickname << "|";
// 	cout << endl;
// 	return (true);
// } ;

// void	Contact::show(void) {
// 	cout << "Name: " << Name << endl;
// 	cout << "Surname: " << Surname << endl;
// 	cout << "Nickname: " << Nickname << endl;
// 	cout << "Number: " << Number << endl;
// 	cout << "Secret: " << Secret << endl;
// } ;
