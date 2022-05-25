/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:40:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/25 14:58:45 by fbarros          ###   ########.fr       */
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

HumanB( std::string _name );
void	setWeapon(Weapon& _weapon);
void	attack( void );

};

#endif /* HUMAN_B_H */
