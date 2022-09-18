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
	// ClapTrap	clappy("Clappy");
	// ScavTrap	scavy("Scavy");
	// FragTrap	fraggy("Fraggy");
	DiamondTrap	diana("Diana");
	// DiamondTrap	diana_clone(diana);
	// std::cout << "\n";
	// ClapTrap	*diana_ptr = &diana;
	// ClapTrap	diana_clapton(*diana_ptr);

	std::cout << "\n";

	return (0);
}

