/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:39 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/20 17:01:31 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( ) {
	this->_name = "Default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->damage = 20;

	std::cout << "ScavTrap " << _name << ": [CONSTRUCTED]\n";
}

// Base class initialization mandatory here
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name)
{

	if (this != &other)
	{
		*this = other;
	}

	std::cout << "ScavTrap " << _name << ": [COPY CONSTRUCTOR CALLED]\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	
	if (this != &other)
	{
		this->_name = "clone_" + other._name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->damage = other.damage;
	}

	std::cout << "ScavTrap " << other._name << ": [ASSIGNED CLONE]\n";
	
	return *this;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->damage = 20;

	std::cout << "ScavTrap " << name << ": [CONSTRUCTED]\n";
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << _name << ": [DESTRUCTED]\n";
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << _name << ": Attacks " << target << "\n";

	if (hit_points > 0 || energy_points > 0)
		energy_points--;
	else if (energy_points == 0)
		std::cout << "ScavTrap " << _name << ": energy = 0.\n";
	else if (hit_points == 0)
		std::cout << "ScavTrap " << _name << ": hitpoints = 0.\n";
}

void	ScavTrap::guardGate() {
	if (hit_points == 0)
		std::cout << "ScavTrap " << _name << " is too dead for gate keeper mode.\n";
	else
		std::cout << "ScavTrap " << _name << ": [GATE KEEPER MODE ON!]\n";
}