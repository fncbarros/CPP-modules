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

DiamondTrap::DiamondTrap() {
	FragTrap ftmp;
	ScavTrap stmp;

	DiamondTrap::_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
	this->hit_points =  ftmp.getHitPoints();
	this->energy_points = stmp.getEnergyPoints();
	this->damage = ftmp.getDamage();

	std::cout << "DiamondTrap" << _name << "called\n";

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
ClapTrap(other.ClapTrap::_name),
ScavTrap(other._name),
FragTrap(other._name)
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
	FragTrap ftmp(name + "FragTemp");
	ScavTrap stmp(name + "ScavTemp");

	this->ClapTrap::_name = name + "_clap_name";
	this->DiamondTrap::_name = name;
	this->hit_points =  ftmp.getHitPoints();
	this->energy_points = stmp.getEnergyPoints();
	this->damage = ftmp.getDamage();

	std::cout << "DiamondTrap " << this->_name << ": [CONSTRUCTED]\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destructed.\n";
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
