/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 13:09:35 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called.\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other)
: Animal(),
brain(NULL) {
    std::cout << "Cat copy constructor called.\n";

    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called.\n";

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

Cat::~Cat( ) {
    std::cout << "Cat destructor called.\n";
	delete brain;
	brain = NULL;
} ;

void Cat::makeSound(void) const {
	std::cout << "Meow\n"; 
}

Brain*	Cat::getBrain(void) const {
	return brain;
}