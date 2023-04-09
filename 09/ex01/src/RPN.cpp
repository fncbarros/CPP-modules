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
#include <cstdlib>

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

bool RPN::setStack(std::stringstream& ss)
{
    char c;

    while (true)
    {
        c = ss.get();
        if (ss.eof())
            break ;
        
        if (std::isspace(c))
        {
            continue ;
        }
        
        if (!std::isdigit(c) && !isOperator(c))
        {
            std::cout << "Error" << std::endl;
            return false;
        }

        if (isOperator(c))
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return false;
            }
            compute(c);
        }
        else
        {
            int param = static_cast<int>(c - TO_NUM);
            _stack.push(param);
        }
    }

    std::cout << _stack.top() << std::endl;

    return true;
}

bool RPN::isOperator(const unsigned char& c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

void RPN::compute(const unsigned char& operation)
{
    int a, b, result = {0};

    b = _stack.top();
    _stack.pop();
    a = _stack.top();
    _stack.pop();

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

    _stack.push(result);
}
