/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:41:11 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/11 12:41:51 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1("Reuben", 2);
	Bureaucrat	b2("Scott", 149);
	Bureaucrat	b52;

	std::cout << ++b1 << std::endl;
	std::cout << --b2 << std::endl;
	std::cout << (b52 = b2) << std::endl;

	try {
		b1++;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		b2--;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat	b3("Inácio", -1);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat b3("Kevin", 75);
		Bureaucrat b4 = b3;
		std::cout << b3 << std::endl;
		Bureaucrat b5;
		std::cout << b5.getName() << std::endl;
		std::cout << b5.getGrade() << std::endl;
		b5 = b4;
		std::cout << b5 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat b5("Karina", 199);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
