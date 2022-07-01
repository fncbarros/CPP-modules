/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:35 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 09:36:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual void	makeSound(void) const;
	std::string	getType(void) const;

protected:
	std::string	type;
};

#endif /* ANIMAL_H */
