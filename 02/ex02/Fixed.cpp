/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/17 18:36:13 by fbarros          ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed& other) const {
	return (_rawValue > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const {
	return (_rawValue < other.getRawBits());
}
bool	Fixed::operator>=(const Fixed& other) const {
	return (_rawValue >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_rawValue <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_rawValue == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_rawValue != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) {
	_rawValue += other.getRawBits();
	return *this;
}

Fixed	Fixed::operator-(const Fixed& other) {
	_rawValue -= other.getRawBits();
	return *this;
}

Fixed	Fixed::operator*(const Fixed& other) {
	Fixed	tmp(toFloat() * other.toFloat());

	_rawValue = tmp.getRawBits();
	return *this;
}

Fixed	Fixed::operator/(const Fixed& other) {
	Fixed	tmp(toFloat() / other.toFloat());

	_rawValue = tmp.getRawBits();
	return *this;
}

Fixed	Fixed::operator++( int increment ) {
	(void)increment;
	Fixed	old(*this);

	_rawValue++;
	return old;
}

Fixed	Fixed::operator--( int decrement ) {
	(void)decrement;
	Fixed	old(*this);

	_rawValue--;
	return old;
}

Fixed&	Fixed::operator++( ) {
	_rawValue++;
	return *this;
}

Fixed&	Fixed::operator--( ) {
	_rawValue--;
	return *this;
}

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs) {
	return lhs < rhs ? lhs : rhs;
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	return lhs < rhs ? lhs : rhs;
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs) {
	return lhs > rhs ? lhs : rhs;
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	return lhs > rhs ? lhs : rhs;
}
