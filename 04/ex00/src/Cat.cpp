/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:37:42 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << type << " default constructer called.\n";
}

Cat::Cat(const Cat& other)
: Animal() {
	if (this != &other)
	{
		*this = other;
	}
	std::cout << type << " copy constructer called.\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << type << " assignment operator called.\n";
	return *this;
}

Cat::~Cat( ) {
	std::cout << type << " destructer called.\n";
} ;

void Cat::makeSound(void) const {
	std::cout << "Meow\n"; 
}
