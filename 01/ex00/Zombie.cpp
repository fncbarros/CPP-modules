/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:59:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/12 19:22:32 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	_name = "Default zombie";
}

Zombie::Zombie( string name ) {
	_name = name;
}

Zombie::~Zombie( void ) {
	cout << _name << ": is dead...er.\n";
}

void	Zombie::announce( void ) {
	cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}