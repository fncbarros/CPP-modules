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
#include "Intern.hpp"

int main()
{
    Intern  someRandomIntern;
    Bureaucrat  hal("HAL2000", 80);
    Bureaucrat  greta("Greta", 150);
    Bureaucrat  zaphod("Zaphod", 30);

    Form*   rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Form*   scf = someRandomIntern.makeForm("shrubbery creation form", "Root");
    Form*   ppr = someRandomIntern.makeForm("presidential", "NOXIN");

    hal.signForm(*rrf);
    hal.executeForm(*rrf);
    greta.signForm(*scf);
    greta.executeForm(*scf);
    zaphod.signForm(*ppr);
    zaphod.executeForm(*ppr);

    delete rrf;
}
