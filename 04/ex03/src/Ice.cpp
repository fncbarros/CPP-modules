/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:54 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 16:14:28 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() :
AMateria("ice") {
    // std::cout << this->getType() << " default constructor called.\n";
}

Ice::Ice(const Ice& other) :
AMateria() {
    if (this != &other)
        *this = other;
    // std::cout << this->getType() << " copy constructor called.\n";
}

Ice&    Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->_type = "ice";
    }
    // std::cout << this->getType() << " assignment operator called.\n";
    return *this;
}

Ice::~Ice() {
    // std::cout << this->getType() << " destructor called.\n";
}

AMateria*   Ice::clone() const {
    return new Ice(*this);
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}