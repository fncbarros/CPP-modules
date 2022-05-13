/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:40:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/13 19:57:10 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <string>
#include <iostream>
// # include <iomanip>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class HumanB {

private:
	std::string _name;

public:

	HumanB( void );
	HumanB( std::string name );
	~HumanB( void );

};

#endif /* HUMAN_B_H */
