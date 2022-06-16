/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:24:12 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/16 16:10:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
#define FIXED_H

# include <iostream>
# include <cmath>
// # include <iomanip>
// # include <memory>

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

private:
	int	_value;
	static const int	_fractional = 8;

};

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs);

#endif /* FIXED_H */
