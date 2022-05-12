/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:36:27 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/12 19:50:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, string name) {
	Zombie*	Horde;

	Horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		Horde[i].setName(name);
	}
	return Horde;
} ;
