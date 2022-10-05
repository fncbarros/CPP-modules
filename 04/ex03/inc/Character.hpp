/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:05:38 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/26 19:05:41 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter {
public:
    Character(const std::string name);
    Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    static void drop(AMateria* m);
    static AMateria *pickup(std::string type);

private:
    AMateria*    _slot[4];
    std::string _name;

};

#endif /* CHARACTER_HPP */
