/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:59:02 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 17:12:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) :
_type(type) {
	// std::cout << "Custom constructor called.\n";
}

AMateria::AMateria() {
	// std::cout << "Default constructor called.\n";
}

AMateria::AMateria(const AMateria& other) {
	// std::cout << "Copy constructor called.\n";
	if (this != &other)
	{
		*this = other;
	}
}

AMateria& AMateria::operator=(const AMateria& other) {
	// std::cout << "Assignment operator called.\n";
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "Destructor called.\n";
}

std::string const &	AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "[AMateria] Not a concrete implementation.\n";
}