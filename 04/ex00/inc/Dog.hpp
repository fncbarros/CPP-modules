/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:23 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:15:57 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	void makeSound(void) const;

};

#endif /* DOG_H */
