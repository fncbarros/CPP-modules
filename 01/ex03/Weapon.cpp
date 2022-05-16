/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:57:42 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 20:08:53 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon( void ) {
	// ...
} ;

Weapon::~Weapon( void ) {
	// ...
} ;

Weapon::Weapon( string _type ) : type(_type) {} ;

const string&	Weapon::getType( void ) {
	string&	_type = type;
	return (_type);
} ;

void	Weapon::setType( string _type ) {
	type = _type;
} ;
