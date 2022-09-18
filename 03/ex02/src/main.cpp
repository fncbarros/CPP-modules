/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:36 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/20 17:03:16 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	moreCompleteAttack(ClapTrap& attacker, ClapTrap& victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

int main()
{
	ScavTrap	def;
	ScavTrap	marvin("Marvin");

	std::cout << "\n";

	marvin.attack("Default");
	def.takeDamage(marvin.getDamage());
	def.attack("Marvin");
	marvin.takeDamage(def.getDamage());
	marvin.attack("Default");
	def.takeDamage(marvin.getDamage() + 60);

	std::cout << "\n";

	std::cout << "Marvin hit points: " << marvin.getHitPoints() << "\n";
	std::cout << "Marvin energy points: " << marvin.getEnergyPoints() << "\n";
	marvin.beRepaired(20);
	std::cout << "Marvin hit points: " << marvin.getHitPoints() << "\n";
	std::cout << "Marvin energy points: " << marvin.getEnergyPoints() << "\n";

	std::cout << "\n";

	ScavTrap	clone2(marvin);
	ScavTrap	clone3 = clone2;
	
	std::cout << "\n";

	marvin.guardGate();
	clone2.guardGate();
	clone3.guardGate();
	def.guardGate();

	std::cout << "\n";

	ClapTrap wall_e("Wall-E");
	ClapTrap	*p_marvin = &marvin;
	moreCompleteAttack(*p_marvin, wall_e);

	std::cout << "\n";

	return (0);
}

