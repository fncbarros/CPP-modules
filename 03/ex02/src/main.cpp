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
#include "FragTrap.hpp"

void	Attack(ClapTrap& attacker, ClapTrap& victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

void	showStatus(ClapTrap	*robot) {
	std::cout << robot->getName() << " status\n";
	std::cout << "Hit points: " << robot->getHitPoints() << std::endl;
	std::cout << "Energy points: " << robot->getEnergyPoints() << std::endl;
	std::cout << "Damage: " << robot->getDamage() << std::endl;
	std::cout << std::endl;
}

int	main()
{
	std::cout << "**TEST1**\n";
	FragTrap	frag("Frag");
	ScavTrap	scav("Scav");
	ClapTrap	clap("Clap");

	showStatus(&frag);
	showStatus(&scav);
	showStatus(&clap);

	std::cout << "\n";

	Attack(frag, scav);
	Attack(scav, clap);
	Attack(clap, frag);

	std::cout << "\n";

	showStatus(&frag);
	showStatus(&scav);
	showStatus(&clap);

	std::cout << "\n";

	frag.highFivesGuys();
	std::cout << "\n";
}
