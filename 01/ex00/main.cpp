/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:19:59 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/12 19:22:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie *newzombie = newZombie("NewZombie");
	Zombie zombie;
	Zombie	zombie2("Zombie2");
	
	newzombie->announce();
	zombie.announce();
	zombie2.announce();
	randomChump("RandomChump");

	delete(newzombie);
	return 0;
}
