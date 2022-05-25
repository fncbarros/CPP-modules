/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:57:42 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/25 14:58:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon( string _type ) : type(_type) {} ;

const string&	Weapon::getType( void ) const {
		return (type);
}

void	Weapon::setType( string _type ) {
	type = _type;
}
