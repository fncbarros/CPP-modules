/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:07:58 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/12 17:40:39 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
_name("Anmeldung"), _signed(false), _sign_grade(1), _exec_grade(1) {
	std::cout << *this << " constructed\n";
}

Form::Form(const std::string name, const unsigned int sign_grade, const unsigned int exec_grade) :
_name(name),
_signed(false),
_sign_grade(sign_grade),
_exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if(sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << *this << " constructed\n";
}

Form::Form(const Form& other) :
_name(other._name),
_signed(false),
_sign_grade(other._sign_grade),
_exec_grade(other._exec_grade) {
	std::cout << *this << " copy constructed from " << other.getName() << std::endl;
}

Form& Form::operator=(const Form& other) {
	_signed = other.isSigned();
	return *this;
}

Form::~Form() {
	std::cout << this->_name << " destructed\n";
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::isSigned() const {
	return _signed;
}

unsigned int			Form::getSignGrade() const {
	return _sign_grade;
}

unsigned int			Form::getExecGrade() const {
	return _exec_grade;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() >= this->_sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void    Form::execute(Bureaucrat const & executor) const {
    if (this->isSigned() == false) {
        throw NotSignedException();
    } else if (executor.getGrade() <= this->getExecGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    process();
}

std::ostream&	operator<<(std::ostream& out, Form& form) {
	out << "Form " + form.getName();
	form.isSigned() ? out << " [Signed]" : out << " [Not signed]";
	out	<< ": required grade for signature: " << form.getSignGrade()
		<< "\trequired grade to execute: " << form.getExecGrade();
	return out;
}