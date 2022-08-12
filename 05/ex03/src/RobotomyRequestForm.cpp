/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:06:26 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/16 16:35:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/**
 * Required grades: sign 72, exec 45
 * Makes some drilling noises. Then, informs that <target> has been robotomized
 * successfully 50% of the time. Otherwise, informs that the robotomy failed.*/

RobotomyRequestForm::RobotomyRequestForm() :
Form("Robotomy Request", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
Form("Robotomy Request", 72, 45),
_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecGrade()) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void    RobotomyRequestForm::setTarget(std::string target) {
    this->_target = target;
}

void RobotomyRequestForm::process() const {
    std::cout << "** DRILLING NOISES **\n";
    srand(time(NULL));
    (rand() % 2 == 0) ? std::cout <<  _target << " has been robotomized\n" : std::cout << "Robotomy failed :(\n";
}
