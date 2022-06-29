/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:31 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:12:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << type << " default constructer called.\n";
}

WrongCat::WrongCat(const WrongCat& other)
: WrongAnimal() {
	std::cout << type << " copy constructer called.\n";
	if (this != &other)
	{
		*this = other;
	}
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << type << " assignment operator called.\n";
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat( ) {
	std::cout << type << " destructer called.\n";
} ;

void WrongCat::makeSound(void) const {
	std::cout << "Wrong Meow\n"; 
}
