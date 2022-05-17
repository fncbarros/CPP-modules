/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:45:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 20:03:02 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB( string _name ) {
	name = _name;
}

HumanB::HumanB( void ) {
	// ...
}

HumanB::~HumanB( void ) {
	// ...
}

// stores garbage if not passed by reference because it would keep a copy
void	HumanB::setWeapon( Weapon& _weapon ) {
	weapon = &_weapon;
}

void	HumanB::attack( void ) {
	cout << name << " attacks with their " << weapon->getType() << endl;
}
