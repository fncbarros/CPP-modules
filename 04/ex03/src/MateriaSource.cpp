/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:28:55 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 18:21:56 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    // std::cout << "[MateriaSource] Default constructor called.\n";
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    // std::cout << "[MateriaSource] Copy constructor called.\n";
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != 0)
        {
            delete this->_materias[i];
        }
        other._materias[i] != 0 ? this->_materias[i] = other._materias[i]->clone() : this->_materias[i] = 0;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    // std::cout << "[MateriaSource] Destructor called.\n";
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != 0)
        {
            delete this->_materias[i];
            this->_materias[i] = 0;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = -1;

    while (++i < 4)
    {
        if (this->_materias[i] == 0)
        {
            this->_materias[i] = m;
            break;
        }
    }
    if (i == 4)
        std::cout << "All out of materias.\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = -1;

    while (_materias[++i])
    {
        if (type == _materias[i]->getType())
            break;
    }
    if (i < 4 && _materias[i])
        return _materias[i]->clone();
    return 0;
}
