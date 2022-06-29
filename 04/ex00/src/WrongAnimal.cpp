/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:40 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:14:28 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( ) : type("WrongAnimal") {
	std::cout << type << " default constructer called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << type << " copy constructer called.\n";

	if (this != &other)
	{
		*this = other;
	}
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << type << " assignment operator called.\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal( ) {
	std::cout << type << " destructer called.\n";
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "[Generic WrongAnimal Sound]\n";
}
