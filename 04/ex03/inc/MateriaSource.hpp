/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:23:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 16:31:56 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource&  operator=(const MateriaSource& other);
    ~MateriaSource();
    
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

private:
    AMateria   *_materias[4];
    AMateria    *floor[100];
    size_t      size;
};

#endif /* MATERIASOURCE_HPP */
