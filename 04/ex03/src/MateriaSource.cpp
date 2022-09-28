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

MateriaSource::MateriaSource() :
size(0)
{
    // std::cout << "[MateriaSource] Default constructor called.\n";
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) :
size(0)
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
        if (other._materias[i] != 0) {
            this->_materias[i] = other._materias[i]->clone();
            this->floor[size++] = this->_materias[i];
        } else 
            this->_materias[i] = 0;

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
    for (size_t i = 0; i < size; i++)
    {
        delete this->floor[i];
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
    AMateria *tmp = NULL;

    while (_materias[++i])
    {
        if (type == _materias[i]->getType()) {
            tmp = _materias[i];
            floor[size] = tmp->clone();
            return floor[size++]; 
        }
    }
    return 0;
}
