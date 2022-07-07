/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:09 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 13:09:34 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() {
	type ="Dog";
	brain = new Brain();
	std::cout << type << " default constructor called.\n";
}

Dog::Dog(const Dog& other)
: Animal(),
brain(NULL) {
	if (this != &other)
	{
		*this = other;
	}
	std::cout << type << " copy constructor called.\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		this->type = other.type;
		if (brain != NULL)
			delete brain;
		// deep copy
		this->brain = new Brain(*(other.brain));
	}
	std::cout << type << " assignment operator called.\n";
	return *this;
}

Dog::~Dog( ) {
	delete brain;
	brain = NULL;
	std::cout << type << " destructer called.\n";
}

void Dog::makeSound(void) const {
	std::cout << "Oof\n"; 
}

Brain*	Dog::getBrain(void) {
	return brain;
}