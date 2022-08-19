/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:57:42 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:17:08 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : 
type(type) {
}

const std::string&	Weapon::getType() const {
		return (type);
}

void	Weapon::setType( std::string type ) {
	this->type = type;
}
