/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:12:51 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/12 19:32:25 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie*	zombieHorde(int N, string name);

int	main(void)
{
	Zombie	*horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}

	delete[] horde;
}