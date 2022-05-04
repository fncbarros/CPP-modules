/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:19:59 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/04 13:47:49 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*Zptr;
	Zombie	zombie("StaticZee");

	Zptr = newZombie("DynaZee");
	randomChump("RandomZee");
	Zptr->announce();
	zombie.announce();
	delete(Zptr);
	return 0;
}
