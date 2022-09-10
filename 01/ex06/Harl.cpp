/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:21:16 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/09 17:21:42 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	lvl[0] = "DEBUG";
	lvl[1] = "INFO";
	lvl[2] = "WARNING";
	lvl[3] = "ERROR";
}

void	Harl::debug( void ) {
	cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger.\nI really do!\n\n";
}

void	Harl::info( void ) {
	cout << "[INFO] I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n\n";
}

void	Harl::warning( void ) {
	cout << "[WARNING] I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error( void ) {
	cout << "[ERROR] This is unacceptable, I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level ) {
	int i = -1;
	while (++i < 4) {
		if (level == lvl[i])
			break ;
	}
	
	switch (i)
	{
	case 0:
		debug();
		// fallthrough
	case 1:
		info();
		// fallthrough
	case 2:
		warning();
		// fallthrough
	case 3:
		error();
		break;
	default:
		cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
}

