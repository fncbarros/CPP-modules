/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:47:33 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/20 16:04:49 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	ScavTrap( std::string name);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();

private:

};

#endif /* SCAVTRAP_H */
