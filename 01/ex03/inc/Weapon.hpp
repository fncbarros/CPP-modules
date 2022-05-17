/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:57:39 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 20:08:35 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>
# include <iomanip>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class Weapon {

private:

	string type;

public:

	Weapon( void );
	~Weapon( void );
	Weapon( string _type );
//	Weapon( std::string type );
const string&	getType( void ) const;
void	setType( string _type );

};

#endif /* WEAPON_H */
