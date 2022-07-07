/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:35 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 09:36:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include <string>

class AAnimal {
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	virtual void	makeSound(void) const = 0;
	std::string	getType(void) const;

protected:
	std::string	type;
private:

};

#endif /* AANIMAL_H */
