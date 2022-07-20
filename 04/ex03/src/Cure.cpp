/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:47:00 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 16:14:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:54 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/07 16:43:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() :
AMateria("cure") {
    // std::cout << this->getType() << " default constructor called.\n";
}

Cure::Cure(const Cure& other) :
AMateria() {
    if (this != &other)
        *this = other;
    // std::cout << this->getType() << " copy constructor called.\n";
}

Cure&    Cure::operator=(const Cure& other) {
    if (this != &other) {
        this->_type = "cure";
    }
    // std::cout << this->getType() << " assignment operator called.\n";
    return *this;
}

Cure::~Cure() {
    // std::cout << this->getType() << " destructor called.\n";
}

AMateria*   Cure::clone() const {
    return new Cure(*this);
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}