/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:24:08 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 15:24:11 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>

int main()
{
    std::vector<int> a(1);
    a.push_back(7);
    a.push_back(3);
    std::vector<float> b(0.5);
    b.push_back(7.0);
    b.push_back(3.5);

    std::vector<int>::const_iterator  v_it = easyfind(a, 7);
    
    std::cout << *v_it << std::endl;
    std::cout << *(--v_it) << std::endl;
    std::cout << *(v_it + 2) << std::endl;


    std::vector<float>::const_iterator  b_it = easyfind(b, 7);

    std::cout << *b_it << std::endl;
    std::cout << *(++b_it) << std::endl;
    std::cout << *(b_it - 2) << std::endl;

    std::find(a.begin(), a.end(), 10);


}
