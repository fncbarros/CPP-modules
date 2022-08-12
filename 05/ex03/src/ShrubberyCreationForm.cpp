/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:06:26 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/16 16:35:54 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * ShrubberyCreationForm: Required grades: sign 145, exec 137
 * Create a file <target>_shrubbery in the working directory, and writes ASCII trees
 * inside it.*/

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("Shrubbery Creation", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
Form("Shrubbery Creation", 145, 137),
_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecGrade()) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void    ShrubberyCreationForm::setTarget(std::string target) {
    this->_target = target;
}

void ShrubberyCreationForm::process() const {
    std::string path(_target + "_shrubbery");
    std::ofstream   file;
    file.open(path.c_str());
    if (!file) {
        std::cerr << "Failed to create shrubbery file\n";
        return ;
    }
    file << "                   # #### ####\n"
    << "                ### \\/#|### |/####\n"
    << "                ##\\/#/ \\||/##/_/##/_#\n"
    << "                ###  \\/###|/ \\/ # ###\n"
    << "            ##_\\_#\\_\\## | #/###_/_####\n"
    << "           ## #### # \\ #| /  #### ##/##\n"
    << "           __#_--###`  |{,###---###-~\n"
    << "                       \\ }{\n"
    << "                       }}{\n"
    << "                       }}{\n"
    << "                   ejm  {{}\n"
    << "               , -=-~{ .-^- _" << std::endl;
    file.close();
}
