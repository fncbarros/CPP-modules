/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:13:50 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/08 11:13:57 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <stack>
#include <list>


class RPN {
public:
    static const short TO_NUM = 0x30;

public:
    RPN();
    RPN(std::stringstream& ss);
    RPN(const RPN& other);
    RPN operator=(const RPN& other);

    bool setStack(std::stringstream& ss);
    void setStack(std::string& s);
    std::string getResult();

private:
    bool isOperator(const unsigned char& c);
    void compute(const unsigned char& operation);

    std::stack<int> _stack;

};
