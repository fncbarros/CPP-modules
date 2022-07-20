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

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("Tree", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) :
Form(name, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
Form(other.getName(), other.getSignGrade(), other.getExecGrade()) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        this->
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // ...
}

void ShrubberyCreationForm::drawTree(std::string target) {
    std::ofstream   file(target + "_shrubery");
    file << "                   # #### ####\n \
                    ### \\/#|### |/####\n \
                    ##\\/#/ \\||/##/_/##/_#\n \
                    ###  \\/###|/ \\/ # ###\n \
                ##_\\_#\\_\\## | #/###_/_####\n \
                ## #### # \\ #| /  #### ##/##\n \
                __#_--###`  |{,###---###-~\n \
                            \\ }{\n \
                            }}{\n \
                            }}{\n \
                        ejm  {{}\n \
                    , -=-~{ .-^- _";
    file.close();
}
