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

void	moreCompleteAttack(ClapTrap& attacker, ClapTrap& victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

int main()
{
	ClapTrap	clap("Clap");
	ScavTrap	scav("Scav");
	FragTrap	frag("Frag");
	DiamondTrap	diamond("Diamond");

	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();

	{
		std::cout << "\n";
		
		ClapTrap	*diamond_ptr = new DiamondTrap("Diamond Clap");
		delete diamond_ptr;

		std::cout << "\n";
	}

	{
		std::cout << "\n";

		ScavTrap	scav2(diamond);
		scav2.guardGate();

		std::cout << "\n";
	}

	{
		std::cout << "\n";

		FragTrap	*frag2 = new DiamondTrap(diamond);
		frag2->highFivesGuys();
		DiamondTrap	*diamondPtr = (DiamondTrap*)frag2;
		diamondPtr->whoAmI();

		std::cout << "\n";

	return (0);
}

