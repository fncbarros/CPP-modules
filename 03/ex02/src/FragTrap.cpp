/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:56:47 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/18 14:56:50 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( ) {
	this->_name = "Default";
	this->hit_points = 100;
	this->energy_points = 100;
	this->damage = 30;

	std::cout << "FragTrap " << _name << ": [CONSTRUCTED]\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name)
{

	if (this != &other)
	{
		*this = other;
	}

	std::cout << "FragTrap " << _name << ": [COPY CONSTRUCTOR CALLED]\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	
	if (this != &other)
	{
		this->_name = "clone_" + other._name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->damage = other.damage;
	}

	std::cout << "FragTrap " << other._name << ": [ASSIGNED CLONE]\n";
	
	return *this;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->damage = 30;

	std::cout << "FragTrap " << name << ": [CONSTRUCTED]\n";
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << _name << ": [DESTRUCTED]\n";
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "HIGH FIVE!\n";
}
