/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:06:26 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/16 16:35:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**
 * Required grades: sign 25, exec 5
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.*/

PresidentialPardonForm::PresidentialPardonForm() :
Form("Presidential Pardon", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
Form("Presidential Pardon", 25, 5),
_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecGrade()),
_target(other._target){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void)other;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void    PresidentialPardonForm::setTarget(std::string target) {
    this->_target = target;
}

void PresidentialPardonForm::process() const {
    std::cout << _target << " is hereby pardoned by President Zaphod Beeblebrox\n";
}
