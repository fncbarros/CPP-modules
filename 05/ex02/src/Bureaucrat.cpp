/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:40 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/12 17:45:06 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name("Beth"), _grade(150) {
	std::cout << "Bureaucrat " << _name << " grade: " << _grade << " constructed\n";
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade) :
_name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " grade: " << _grade << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
_name(other._name), _grade(other._grade) {
	std::cout << _name << " copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << _name << " grade " << _grade << " copied from " << other._name << ".\n";
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << _name << " destructor called.\n";
} ;

std::string	Bureaucrat::getName() const {
	return _name;
}

unsigned int	Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat&	Bureaucrat::operator++() {
	if (this->_grade <= 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
	return *this;
}

Bureaucrat&	Bureaucrat::operator--() {
	if (this->_grade >= 150) {
		throw GradeTooLowException();
	}
	this->_grade++;
	return *this;
}

Bureaucrat	Bureaucrat::operator++(int) {
	Bureaucrat	result(*this);
	++(*this);
	return result;
}

Bureaucrat	Bureaucrat::operator--(int){
	Bureaucrat	result(*this);
	--(*this);
	return result;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
        std::cout << "bureaucrat grade: " << this->_grade << " SIGNING GRADE: " << form.getSignGrade() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form& form) {
    try {
        form.execute(*this);
		std::cout << _name << " executed form " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->_name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}