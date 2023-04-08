/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:14:09 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/08 11:14:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
#include <iostream>
#include <ctype.h>
#include <string>

RPN::RPN()
{
}

RPN::RPN(std::stringstream& ss)
{
    setStack(ss);
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

void RPN::setStack(std::stringstream& ss)
{
    std::string s;

    while (!ss.eof())
    {
        ss >> s;
        if (!validate(s))
        {
            return ;
        }

        if (isOperator(s[0]))
        {
            const unsigned char c(s[0]);
            compute(c);
        }
        else
        {
            _stack.push(s);
        }
    }
}

bool RPN::isOperator(const unsigned char& c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

bool RPN::validate(const std::string& s)
{
    bool valid = true;

    if (s.size() > 1)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            valid &= std::isdigit(s[i]);
        }
    }
    else
    {
        char c = s[0];
        valid = (std::isdigit(c)) || (isOperator(c));
    }

    if (!valid)
    {
        std::cerr << "Error" << std::endl;
    }
    return valid;
}

void RPN::compute(const unsigned char& operation)
{
    short a, b, result = {0};
    std::stringstream ss;

    ss << _stack.top();
    _stack.pop();
    ss << _stack.top();
    _stack.pop();

    ss >> a;
    ss >> b;
    std::string s;

    switch(operation)
    {
        case '+':
            result = a + b;
            break ;
        case '-':
            result = a - b;
            break ;
        case '*':
            result = a * b;
            break ;
        case '/':
            result = a / b;
    }
    ss << result;
    ss >> s;
    _stack.push(s);
}

std::string RPN::getResult()
{

    return _stack.top();
}