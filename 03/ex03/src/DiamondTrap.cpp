/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:50:43 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/24 18:36:33 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// • Name, which is passed as parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (Scavtrap)

DiamondTrap::DiamondTrap( ) {
	FragTrap ftmp();
	ScavTrap stmp();

	this->_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
	this->hit_points =  getHitPoints();
	this->energy_points = ScavTrap::energy_points;
	this->damage = FragTrap::damage;

	std::cout << "DiamondTrap" << _name << "called\n";

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
ClapTrap(other.ClapTrap::_name),
ScavTrap(),
FragTrap()
{
		*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->ClapTrap::_name = other.ClapTrap::_name;
		this->_name = other.hit_points;
		this->_name = other.energy_points;
		this->_name = other.damage;
	}
	return *this;
}

DiamondTrap::DiamondTrap( std::string name )
{
	this->_name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->damage = FragTrap::damage;
	ScavTrap::_name = name;
	this->ClapTrap::_name = name + "_clap_name";

	std::cout << "DiamondTrap " << this->_name << ": [CONSTRUCTED]\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destructed.\n";
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
