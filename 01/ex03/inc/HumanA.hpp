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

#include <string>
#include <iostream>
// # include <iomanip>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class HumanA {

private:
	std::string	_name;

public:

	HumanA( void );
	HumanA( std::string name );
	~HumanA( void );

};

#endif /* HUMAN_A_H */
