/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:30:21 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/03 20:30:26 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

    Form    *makeForm(std::string form, const std::string& target);

private:
    struct  s_form_table {
        std::string form;
        Form    *(*func)(const std::string );
    }   form_table[3];
    void    initTable();
    static Form    *makeShrubbery(const std::string target);
    static Form    *makeRobotomy(const std::string target);
    static Form    *makePardon(const std::string target);
    std::string    stoLower(const std::string& s);
};

#endif /* INTERN_HPP */
