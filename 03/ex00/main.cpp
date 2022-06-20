/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:36 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/20 13:07:06 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

void	moreCompleteAttack(ClapTrap& attacker, ClapTrap& victim)
{
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
}

int main()
{
	ClapTrap	def;
	ClapTrap	wall_e("Wall-E");
	
	std::cout << "\n";

	moreCompleteAttack(def, wall_e);
	moreCompleteAttack(wall_e, def);

	std::cout << "\n";
	
	wall_e.beRepaired(1);
	std::cout << "\n";


	ClapTrap	clone1(def);
	ClapTrap	clone2 = wall_e;
	clone1 = clone2;

	std::cout << "\n";
	
	return (0);
}

