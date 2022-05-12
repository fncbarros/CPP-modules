/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:48:59 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/12 19:46:52 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

using	std::string;
using	std::cout;
using	std::endl;

class Zombie {

private:

	string	_name;

public:

	Zombie(void);
	Zombie(string name);
	~Zombie( void );
	void	setName(string name);

void	announce( void );
} ;

Zombie*	zombieHorde(int N, string name);


#endif /* ZOMBIE_H */
