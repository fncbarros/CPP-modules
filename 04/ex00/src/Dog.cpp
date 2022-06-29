/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:09 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:37:32 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() {
	type ="Dog";
	std::cout << type << " default constructer called.\n";
}

Dog::Dog(const Dog& other)
: Animal() {
	if (this != &other)
	{
		*this = other;
	}
	std::cout << type << " copy constructer called.\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << type << " assignment operator called.\n";
	return *this;
}

Dog::~Dog( ) {
	std::cout << type << " destructer called.\n";
}

void Dog::makeSound(void) const {
	std::cout << "Oof\n"; 
}
