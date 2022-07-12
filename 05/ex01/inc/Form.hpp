/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:41:02 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/12 17:17:16 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string name, const unsigned int sign_grade, const unsigned int exec_grade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	class GradeTooHighException : public std::exception {
		const char *what() const throw() {
			return "Grade too high!";
		}
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw() {
			return "Grade too low!";
		}
	};

	std::string	getName() const;
	bool		isSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void	beSigned(Bureaucrat& bureaucrat);

private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_sign_grade;
	const unsigned int	_exec_grade;
};

	std::ostream&	operator<<(std::ostream& out, Form& form);

#endif /* FORM_HPP */
