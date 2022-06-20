/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:39 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/20 15:55:45 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap( ) :
	_name("Default"),
	hit_points(10),
	energy_points(10),
	damage(0)
	{
	std::cout << "ClapTrap " << _name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	if (this != &other)
	{
		*this = other;
	}

	std::cout << "ClapTrap " << _name << " constructed from " << other._name << ".\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		_name = "clone_" + other._name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		damage = other.damage;
	}

	std::cout << "ClapTrap " << _name << " assigned from " << other._name << ".\n";
	
	return *this;
}

ClapTrap::ClapTrap( std::string name ) :
	_name(name),
	hit_points(10),
	energy_points(10),
	damage(0)
	{
	std::cout << "ClapTrap " << name << " constructed.\n";
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << _name << " destructed.\n";
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << damage << " points of damage.\n";

	if (hit_points > 0 || energy_points > 0)
		energy_points--;
	else if (energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy left.\n";
	else if (hit_points == 0)
		std::cout << "ClapTrap " << _name << " is dead.\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage.\n";

	if (hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is already dead.\n";
		return ;
	}
	if (amount >= hit_points) {
		std::cout << "ClapTrap " << _name << " died.\n";
		hit_points = 0;
	}
	else
		hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " recovers " << amount << " hit points.\n";

	if (hit_points > 0 || energy_points > 0)
	{
		hit_points += amount;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy left.\n";
	else if (hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead.\n";
}

std::string	ClapTrap::getName( void ) {
	return (_name);
}

int	ClapTrap::getHitPoints( void ) {
	return (hit_points);
}

int	ClapTrap::getEnergyPoints( void ) {
	return (energy_points);
}

int	ClapTrap::getDamage( void ) {
	return (damage);
}
