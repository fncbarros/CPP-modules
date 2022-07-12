/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:42 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/12 16:48:35 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

#include "Form.hpp"
class Form;

class Bureaucrat {
public:
	Bureaucrat(const std::string name, const unsigned int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

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
	unsigned int	getGrade() const;

	Bureaucrat&	operator++();
	Bureaucrat&	operator--();
	Bureaucrat	operator++(int);
	Bureaucrat	operator--(int);

	void	signForm(Form & form);

private:
	const std::string	_name;
	unsigned int	_grade;

};

	std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif /* BUREAUCRAT_H */
