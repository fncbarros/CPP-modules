/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:45:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:13:53 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string _name ) :
name(_name) {
	std::cout << "HumanB Constructor constructor called.\n";
}

void	HumanB::setWeapon( Weapon& _weapon ) {
	weapon = &_weapon;
}

void	HumanB::attack( void ) {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
