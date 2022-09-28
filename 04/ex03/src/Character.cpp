/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:49 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 18:22:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : _name(name)
{
    // std::cout << this->getName() << " constructed.\n";
    for (int i = 0; i < 4; i++)
        _slot[i] = 0;
}

Character::Character() : _name("Doe")
{
    // std::cout << this->getName() << " default constructor called.\n";
    for (int i = 0; i < 4; i++)
        _slot[i] = 0;
}

Character::Character(const Character &other)
{
    // std::cout << this->getName() << " copy constructor called.\n";
    if (this != &other)
        *this = other;
}

Character &Character::operator=(const Character &other)
{
    // std::cout << this->getName() << " assignment operator called.\n";
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_slot[i] != 0)
                delete this->_slot[i];
            other._slot[i] != 0 ? this->_slot[i] = other._slot[i]->clone() : this->_slot[i] = 0;
        }
        this->_name = other.getName();
    }
    return *this;
}

Character::~Character()
{
    // std::cout << this->getName() << " destructor called.\n";
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    int i = -1;

    while (++i < 4)
    {
        if (this->_slot[i] == 0)
        {
            this->_slot[i] = m;
            break;
        }
    }
    if (i == 4)
        std::cout << "[" << this->getName() << "] Slots full!\n";
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->_slot[idx] != NULL)
    {
        _slot[idx] = 0;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_slot[idx])
        this->_slot[idx]->use(target);
}
