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

void Attack(ClapTrap &attacker, ClapTrap &victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

void test2()
{
	std::cout << "\n**TEST2**\n";
	ClapTrap *CTPtr = new ScavTrap("VIRTUAL_DESTRUCTOR_EXAMPLE");
	CTPtr->attack("**test attack**");
	delete CTPtr;
	std::cout << std::endl;
}

void test1()
{
	std::cout << "**TEST1**\n";
	ScavTrap def;
	ScavTrap marvin("Marvin");

	std::cout << "\n";

	Attack(marvin, def);
	Attack(def, marvin);
	marvin.guardGate();
	def.guardGate();

	std::cout << "\n";

	marvin.takeDamage(100);
	marvin.attack("nobody");
	marvin.guardGate();

	std::cout << "\n";
	{
		std::cout << "\n**TEST3**\n";

		ScavTrap marvin2(marvin);
		ClapTrap wall_e("Wall-E");
		ClapTrap *p_marvin = &marvin;
		Attack(*p_marvin, wall_e);

		std::cout << "\n";
	}
	std::cout << "\n";
}

int main()
{
	test1();
	test2();

	return (0);
}