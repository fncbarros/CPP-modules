/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:21:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/09 17:16:19 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
// # include <iomanip>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;


class Harl {

public:
	Harl();
	void	complain( std::string level );

private:
	struct _lut
	{
		string		level;
		void	(Harl::*f)( void );
	};
	struct _lut	lut[4];
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};

#endif /* HARL_HPP */
