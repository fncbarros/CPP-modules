/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:12:51 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/12 19:38:44 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*ZHorde;

	ZHorde = zombieHorde(5, "Lester");
	for (int i = 0; i < 5; i++) {
		ZHorde[i].announce();
	}
	
	delete[] ZHorde;
}