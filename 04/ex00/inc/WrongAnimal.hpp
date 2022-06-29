/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:35 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:15:38 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	void	makeSound(void) const;
	std::string	getType(void) const;

protected:
	std::string	type;
};

#endif /* WRONG_ANIMAL_H */
