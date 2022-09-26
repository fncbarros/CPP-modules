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
    std::cout << "Dog default constructor called.\n";
	type ="Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other)
: AAnimal(),
brain(NULL) {
    std::cout << "Dog copy constructor called.\n";

    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called.\n";
	if (this != &other)
	{
		this->type = other.type;
		if (brain != NULL) {
            delete brain;
            brain = NULL;
        }
		// deep copy
		this->brain = new Brain(*(other.brain));
	}
	return *this;
}

Dog::~Dog( ) {
    std::cout << "Dog destructor called.\n";
	delete brain;
	brain = NULL;
}

void Dog::makeSound(void) const {
	std::cout << "Oof\n"; 
}

Brain*	Dog::getBrain(void) const {
	return brain;
}