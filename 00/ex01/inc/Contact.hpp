/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/30 19:50:08 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * "Any function implemented in a header
 *  (except in the case of templates), and anyunprotected header means 0 to the exercise."
 *
 * "Each of your includes must be able to be included
 * independently from others.Includes must contain every other includes they are depending on."
*/

#ifndef PHONE_HPP
#define PHONE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::stringstream;

class	Contact {
	private:

		bool		exists;
		string		Name;
		string		Surname;
		string		Nickname;
		string		Number;
		string		Secret;

	public:

		Contact(void);
		~Contact(void);
		string	getName(void);
		string	getSurname(void);
		string	getNickname(void);
		string	getNumber(void);
		string	getSecret(void);
		void	setName(string _Name);
		void	setSurname(string _Surname);
		void	setNickname(string _Nickname);
		void	setNumber(string _Number);
		void	setSecret(string _Secret);
		void	add(void);
		string	getAlpha(string prompt);
		string	getNum(string prompt);
		void	printInfo(int index); 
		void	show(void);

};

#endif	/* PHONE_HPP */
