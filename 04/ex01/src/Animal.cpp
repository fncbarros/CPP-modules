/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:40 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 09:36:20 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal( ) : type("Animal") {
	std::cout << type << " default constructer called.\n";
}

Animal::Animal(const Animal& other) {
	std::cout << type << " copy constructer called.\n";

	if (this != &other)
	{
		*this = other;
	}
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << type << " assignment operator called.\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal( ) {
	std::cout << type << " destructor called.\n";
}

std::string	Animal::getType(void) const {
	return (type);
}

void	Animal::makeSound(void) const {
	std::cout << "[Generic Animal Sound]\n";
}
