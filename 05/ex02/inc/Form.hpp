/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:41:02 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/13 09:05:33 by fbarros          ###   ########.fr       */
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
	virtual ~Form();

	class GradeTooHighException : public std::exception {
    private:
		const char *what() const throw() {
			return "Grade too high!";
		}
	};

	class GradeTooLowException : public std::exception {
    private:
		const char *what() const throw() {
			return "Grade too low!";
		}
	};

    class NotSignedException : public std::exception {
    private:
        const char *what() const throw() {
            return "Form not Signed!";
        }
    };

	std::string	getName() const;
	bool		isSigned() const;
	unsigned int			getSignGrade() const;
	unsigned int			getExecGrade() const;

	void	beSigned(Bureaucrat& bureaucrat);

    void    execute(Bureaucrat const& executor) const;

protected:
    virtual void    process() const = 0;

private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_sign_grade;
	const unsigned int	_exec_grade;
};

std::ostream&	operator<<(std::ostream& out, Form& form);

#endif /* FORM_HPP */
