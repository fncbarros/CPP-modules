/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:57:39 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:16:42 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>
#include <iomanip>

class Weapon {
public:
Weapon( std::string type );
const std::string&	getType() const;
void	setType( std::string type );

private:
	std::string type;

};

#endif /* WEAPON_H */
