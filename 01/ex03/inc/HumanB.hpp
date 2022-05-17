/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:40:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 19:57:10 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB {

private:

	string name;
	Weapon *weapon;

public:

	HumanB( void );
	HumanB( std::string _name );
	~HumanB( void );
void	setWeapon(Weapon& _weapon);
void	attack( void );

};

#endif /* HUMAN_B_H */
