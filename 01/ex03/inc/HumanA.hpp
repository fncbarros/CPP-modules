/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:50:18 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 19:57:20 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"

class HumanA {

private:
	string	name;
	Weapon	weapon;

public:

	HumanA( std::string _name, Weapon _weapon );
	~HumanA( void );
void	attack( void );

};

#endif /* HUMAN_A_H */
