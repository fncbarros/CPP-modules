/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:45:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 20:02:56 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::~HumanA( void ) {
	// ...
}

// reference needs to be initialized when declared
HumanA::HumanA( std::string _name, Weapon& _weapon ) : name(_name), weapon(_weapon) {
	// weapon = _weapon; // will throw a compiler error for reason mentioned above 
}

void	HumanA::attack( void ) {
	cout << name << " attacks with their " << weapon.getType() << endl; 
}
