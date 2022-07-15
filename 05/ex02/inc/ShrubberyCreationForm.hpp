#ifndef SHRUBBERY_CREATION_FORM_HPP 
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void drawTree();
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */