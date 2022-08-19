/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:50:18 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/19 19:12:47 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
public:
	HumanA( std::string _name, Weapon& _weapon );
	void	attack( void );

private:
	std::string	name;
	Weapon&	weapon;

};

#endif /* HUMANA_H */
