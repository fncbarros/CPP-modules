/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:23:17 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/08 16:03:00 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef I_MATERIA_SOURCE_H
#define I_MATERIA_SOURCE_H

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif /* I_MATERIA_SOURCE_H */