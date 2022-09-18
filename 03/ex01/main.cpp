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

void	Attack(ClapTrap& attacker, ClapTrap& victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

void    test2() {
<<<<<<< HEAD
	std::cout << "\n**TEST2**\n";
=======
>>>>>>> 4e6ae068b6ac1cdea1d1234270ca28cf170fcf90
    ClapTrap    *CTPtr = new ScavTrap("VIRTUAL_DESTRUCTOR_EXAMPLE");
    CTPtr->attack("**test attack**");
    delete CTPtr;
    std::cout << std::endl;
}

<<<<<<< HEAD
void	test1() {
	std::cout << "**TEST1**\n";
=======
int main()
{
>>>>>>> 4e6ae068b6ac1cdea1d1234270ca28cf170fcf90
	ScavTrap	def;
	ScavTrap	marvin("Marvin");
	ScavTrap	marvin2(marvin);

	std::cout << "\n";

<<<<<<< HEAD
	Attack(marvin, def);
	Attack(def, marvin);
=======
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

>>>>>>> 4e6ae068b6ac1cdea1d1234270ca28cf170fcf90
	marvin.guardGate();
	def.guardGate();

	std::cout << "\n";

<<<<<<< HEAD
	marvin2.takeDamage(100);
	marvin2.attack("nobody");
	marvin2.guardGate();
=======
	ClapTrap wall_e("Wall-E");
	ClapTrap	*p_marvin = &marvin;
	Attack(*p_marvin, wall_e);
>>>>>>> 4e6ae068b6ac1cdea1d1234270ca28cf170fcf90

	std::cout << "\n";
}

int main()
{
	test1();
    test2();

    test2();

	return (0);
}

