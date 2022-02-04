/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:59:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/01/28 11:59:50 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/*static Members*/

/*Constructors*/

Zombie::Zombie( void ) {
	// ...
} ;

/*Zombie::Zombie( string name ) {
	this->name = name;
} ;*/

/*Destructor*/

Zombie::~Zombie( void ) {
	cout << name << ": is dead...er." << endl;
} ;

void	Zombie::announce( void ) {
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
} ;


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
