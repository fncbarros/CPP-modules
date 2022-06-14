/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/14 22:00:45 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called.\n";
} ;

/**
 * Commented options work just as well but I guess
 * it's not compliant with the Orthodox Canonical Form
 */
Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called.\n";

	if (this != &other)
	{
		// *this = other;
		// setRawBits(other.getRawBits());
		_value = other.getRawBits();
	}
} ;

/**
 * Commented options work just as well but I guess
 * it's not compliant with the Orthodox Canonical Form
 */
Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called.\n";

	if (this != &other) {
		// this->_value = other._value;
		// setRawBits(other.getRawBits());
		_value = other.getRawBits();
	}
	return (*this);
} ;

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
} ;

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called.\n";

	return (_value);
} ;

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called.\n";

	_value = raw;
} ;