/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/16 17:00:05 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called.\n";

	if (this != &other)
	{
		*this = other;
	}
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called.\n";

	if (this != &other) {
		setRawBits(other.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

int	Fixed::getRawBits( void ) const {
	return (_rawValue);
} 

void	Fixed::setRawBits( int const raw ) {
	_rawValue = raw;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called.\n";

	setRawBits(integer << _fractional);
}

Fixed::Fixed(const float floating){
	std::cout << "Float constructor called.\n";

	setRawBits(int(roundf(floating * (1 << _fractional))));
}

float	Fixed::toFloat( void ) const {
	float f = float(getRawBits()) / (1 << _fractional);
	return (f);
}

int	Fixed::toInt( void ) const {
	return (getRawBits() >> _fractional);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
