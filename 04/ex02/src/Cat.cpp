/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 13:33:16 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << type << " default constructor called.\n";
}

Cat::Cat(const Cat& other)
: AAnimal(),
brain(NULL) {
	if (this != &other)
	{
		*this = other;
	}
	std::cout << type << " copy constructor called.\n";
}

Cat& Cat::operator=(const Cat& other) {
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

Cat::~Cat( ) {
	delete brain;
	brain = NULL;
	std::cout << type << " destructor called.\n";
} ;

void Cat::makeSound(void) const {
	std::cout << "Meow\n"; 
}

Brain*	Cat::getBrain(void) const {
	return brain;
}