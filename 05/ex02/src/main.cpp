/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:15:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/20 22:17:14 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    test_shrubbery() {
    std::cout << "\n***SHRUBBERY CREATION TEST***" <<std::endl;

    Bureaucrat  greta("Greta", 150);
    Bureaucrat  jessica("Jessica", 70);
    ShrubberyCreationForm No1("theLarch");
    std::cout << std::endl;

    greta.executeForm(No1);
    jessica.executeForm(No1);
    greta.signForm(No1);
    jessica.executeForm(No1);
    greta.executeForm(No1);

    std::cout << std::endl;
}

void    test_robotomy() {
    std::cout << "\n***ROBOTOMY REQUEST TEST***" <<std::endl;

    Bureaucrat  hal("HAL2000", 80);
    Bureaucrat  jessica("Jessica", 46);
    RobotomyRequestForm f0("f0rm");
    RobotomyRequestForm f1("f1rm");
    RobotomyRequestForm f2("f2rm");
    RobotomyRequestForm f3("f3rm");
    std::cout << std::endl;

    hal.executeForm(f0);
    hal.executeForm(f0);
    hal.signForm(f0);
    hal.signForm(f1);
    hal.signForm(f2);
    hal.signForm(f3);
    std::cout << std::endl;

    jessica.executeForm(f0);
    jessica.executeForm(f1);
    jessica.executeForm(f2);
    jessica.executeForm(f3);

    std::cout << std::endl;
}

void    test_pardon() {
    std::cout << "\n***PRESIDENTIAL PARDON***" <<std::endl;

    Bureaucrat  zaphod("Zaphod", 30);
    Bureaucrat  zarniwoop("Zarniwoop", 4);
    PresidentialPardonForm arthur("Arthur");
    std::cout << std::endl;

    zaphod.executeForm(arthur);
    zarniwoop.executeForm(arthur);
    zaphod.signForm(arthur);
    zarniwoop.executeForm(arthur);
    zaphod.executeForm(arthur);

    std::cout << std::endl;
}

int main()
{
    // Form f("test", 1, 1); // should not compile
    test_shrubbery();
    test_robotomy();
    test_pardon();
}
