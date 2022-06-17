/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:12 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/17 18:14:27 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
#define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int natural);
	Fixed(const float real);
	Fixed& operator=(const Fixed& other);
	~Fixed ();

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int	toInt( void ) const;

	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	// post
	Fixed	operator++( int increment );
	Fixed	operator--( int decrement );
	// pre
	Fixed&	operator++( );
	Fixed&	operator--( );

	static Fixed&	min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&	max(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

private:
	int	_rawValue;
	static const int	_fractional = 8;

};

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs);

#endif /* FIXED_H */
