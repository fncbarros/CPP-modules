#ifndef SHRUBBERY_CREATION_FORM_HPP 
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

#include <fstream>
class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void drawTree(std::string path);
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */