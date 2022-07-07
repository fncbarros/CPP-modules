/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:23 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 12:20:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	void makeSound(void) const;
	Brain	*getBrain(void);

private:
	Brain	*brain;
};

#endif /* DOG_H */
