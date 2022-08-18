/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:29:54 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/03 20:30:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	// std::cout << "[Intern] Default constructor called.\n";
    initTable();
}

Intern::Intern(const Intern& other) {
	// std::cout << "[Intern] Copy constructor called.\n";
    (void)other;
    initTable();
}

Intern& Intern::operator=(const Intern& other) {
	// std::cout << "[Intern] Assignment operator called.\n";
    (void)other;
	return *this;
}

Intern::~Intern() {
	// std::cout << "[Intern] Destructor called.\n";
} ;

Form    *Intern::makeForm(std::string form,const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (form_table[i].form.find(stoLower(form)) != std::string::npos)
            return form_table[i].func(target);
    }
    std::cerr << "Could not find form!\n";
    return NULL;
}

void    Intern::initTable() {
    form_table[0].form = "shrubbery creation form";
    form_table[0].func = makeShrubbery;
    form_table[1].form = "robotomy request form";
    form_table[1].func = makeRobotomy;
    form_table[2].form = "presidential pardon form";
    form_table[2].func = makePardon;
}

Form    *Intern::makeShrubbery(std::string target) {
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

Form    *Intern::makeRobotomy(const std::string target) {
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}

Form    *Intern::makePardon(const std::string target) {
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}

std::string    Intern::stoLower(const std::string& s) {
    std::string s2(s);
    for (size_t i = 0; i < s2.size(); i++) {
        if (s2[i] > 64 && s2[i] < 91)
            s2[i] += (97 - 65);
    }
    return s2;
}