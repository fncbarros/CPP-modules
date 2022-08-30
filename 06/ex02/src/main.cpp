/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:35 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/29 15:38:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <exception>

Base    *generate(void) {
    srand(time(0));
    int i = rand() % 3;

    switch (i) {
        case 0 :
            return new A;
        case 1 :
            return new B;
        case 2 :
            return new C;
        }
    return NULL;
}

void    identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Derived class is of type A.\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Derived class is of type B.\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Derived class is of type C.\n";
    else
        std::cout << "Object not derived from Base class.\n";
}

void    identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "Derived class is of type A.\n";
        return ;
    } catch(std::exception& e) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "Derived class is of type B.\n";
        return ;
    } catch(std::exception& e) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "Derived class is of type C.\n";
        return ;
    } catch(std::exception& e) {}
    std::cout << "Object not derived from Base class.\n";
}

int main()
{
    Base *ptr = generate();
    std::cout << "identify(pointer to Base):\n\t";
    identify(ptr);
    std::cout << "identify(Base reference):\n\t";
    identify(*ptr);
    Base a;
//    identify(&a);
//    identify(a);
    delete ptr;
	return (0);
}

