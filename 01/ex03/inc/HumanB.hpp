/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:40:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:06:46 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
public:
	HumanB( std::string _name );
	void	setWeapon(Weapon& _weapon);
	void	attack( void );

private:
	std::string name;
	Weapon *weapon;

};

#endif /* HUMANB_H */
