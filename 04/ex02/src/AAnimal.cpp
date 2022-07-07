/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:40 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 13:09:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( ) : type("AAnimal") {
	std::cout << type << " default constructor called.\n";
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << type << " copy constructor called.\n";

	if (this != &other)
	{
		*this = other;
	}
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << type << " assignment operator called.\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal( ) {
	std::cout << type << " destructor called.\n";
}

std::string	AAnimal::getType(void) const {
	return (type);
}
