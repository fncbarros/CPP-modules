/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:06:26 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/13 21:05:53 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("Tree", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    if (this != &other)
        *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::drawTree() {
    
}

