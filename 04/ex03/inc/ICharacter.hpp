/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:48:42 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 17:16:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>
#include "AMateria.hpp"
class AMateria; // look it up

class ICharacter {
public:
    virtual ~ICharacter() {} // won't compile if not "implemented" (... ~ICharacter();<-- notice the semicolon)
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif /* ICHARACTER_H */