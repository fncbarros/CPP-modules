/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:36 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/24 14:23:19 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void Attack(ClapTrap &attacker, ClapTrap &victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

void showDiamondStatus(DiamondTrap &obj)
{
	std::cout << "Status:\n";
	obj.whoAmI();
	std::cout << "Hit points: " << obj.getHitPoints() << std::endl;
	std::cout << "Energy points: " << obj.getEnergyPoints() << std::endl;
	std::cout << "Damage: " << obj.getDamage() << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "**TEST1**\n";
	ClapTrap clap("Clap");
	std::cout << "\n";
	ScavTrap scav("Scav");
	std::cout << "\n";
	FragTrap frag("Frag");
	std::cout << "\n";
	DiamondTrap diamond("Diamond");
	std::cout << "\n";

	showDiamondStatus(diamond);
	diamond.attack("Frag");
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout << "\n";

	{
		std::cout << "\n**TEST2**\n\n";

		ClapTrap *diamond_ptr = new DiamondTrap("Diamond Clap");
		delete diamond_ptr;

		std::cout << "\n";
	}

	{
		std::cout << "\n**TEST3**\n\n";

		ScavTrap scav2(diamond);
		scav2.guardGate();
		Attack(scav2, diamond);

		std::cout << "\n";
	}

	{
		std::cout << "\n**TEST4**\n\n";

		FragTrap *frag2 = new DiamondTrap(diamond);
		frag2->highFivesGuys();
		DiamondTrap *diamondPtr = dynamic_cast<DiamondTrap *>(frag2);
		diamondPtr->whoAmI();

		std::cout << "\n";
	}
	std::cout << "\n";
	return (0);
}
