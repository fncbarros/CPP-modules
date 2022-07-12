/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:15:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/12 17:44:12 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	testNums(unsigned int a, unsigned int b) {
	try {
		Form f("f", a, b);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	testSignature(Bureaucrat& buro, Form& form) {
	
	std::cout << buro.getName() << " grade " << buro.getGrade() << std::endl;
	std::cout << form.getName() << " signature grade " << form.getSignGrade() << std::endl;

	try {
		form.beSigned(buro);
		std::cout << "Signed!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	Form f1;
	/**
	 * Getters
	 */
	std::cout << "\n/**Getters**\\" << std::endl;
	std::cout << "name " << f1.getName() << std::endl;
	std::cout << "is signed " << f1.isSigned() << std::endl;
	std::cout << "sign grade " << f1.getSignGrade() << std::endl;
	std::cout << "exec grade " << f1.getExecGrade() << std::endl;
	/**
	 * Construction tests
	 */
	std::cout << "\n/**Constructors**\\" << std::endl;
	Form f2("Abmeldung", 13, 9);
	Form f3(f1);
	std::cout << std::endl;

	/**
	 * operator<< and operator=
	 */
	std::cout << "\n/**operator<<**\\" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << "\n/**operator=**\\" << std::endl;
	f3 = f2;
	std::cout << "f3 copied from f1" << std::endl;
	std::cout << f3 << std::endl;
	std::cout << std::endl;
	
	/**
	 * Invalid numbers
	 */
	std::cout << "\n/**Invalid numbers**\\" << std::endl;
	testNums(0, 1);
	testNums(1, 0);
	testNums(151, 1);
	testNums(1, 151);

	std::cout << std::endl;
	Bureaucrat	stevie("Stevie", 13);
	Bureaucrat	monika("Monika", 1);

	std::cout << "\n/**Bureaucrat::signForm()**\\" << std::endl;
	/**
	 * Bureaucrat::signForm && Form::beSigned
	 */
	stevie.signForm(f1);
	monika.signForm(f1);

	std::cout << "\n/**Form::beSigned()**\\" << std::endl;
	testSignature(stevie, f3);
	testSignature(monika, f3);

}
