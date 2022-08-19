/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:45:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:13:09 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon& _weapon ) : 
name(_name),
weapon(_weapon) {
	std::cout << "HumanA Constructor called.\n";
}

void	HumanA::attack( void ) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl; 
}
