/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:48:59 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/12 19:18:18 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

using	std::string;
using	std::cout;
using	std::endl;

class Zombie {
public:
	Zombie();
	Zombie(string name);
	~Zombie( void );

	void	announce( void );

private:
	string	_name;

};

#endif /* ZOMBIE_H */
