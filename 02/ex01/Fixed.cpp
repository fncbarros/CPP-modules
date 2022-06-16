/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/16 16:42:37 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
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
	return (_value);
} 

void	Fixed::setRawBits( int const raw ) {
	_value = raw;
}

Fixed::Fixed(const int natural) {
	std::cout << "Int constructor called.\n";

	setRawBits(natural << _fractional);
}

Fixed::Fixed(const float real){
	std::cout << "Float constructor called.\n";

	setRawBits(int(roundf(real * (1 << _fractional))));
}

float	Fixed::toFloat( void ) const {
	float f = float(getRawBits()) / (1 << _fractional);
	return (f);
}

int	Fixed::toInt( void ) const {
	return (getRawBits() >> _fractional);
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs) {
	lhs << rhs.toFloat();
	return (lhs);
}
