/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:07:01 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/10 20:07:46 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <ctime>


class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(std::stringstream& ss);
    PmergeMe(const PmergeMe& other);
    PmergeMe operator=(const PmergeMe& other);
    ~PmergeMe();

    void runVector();
    void runDeque();
    void runBoth();
    bool containersSet();

private:
    void printOrderedSequence();

    std::vector<unsigned int> _vector;
    std::deque<unsigned int> _deque;
    double _vectorTime;
    double _dequeTime;

};

template<typename Iterator>
void insertion_sort(Iterator left, Iterator right);

template<typename Iterator>
void merge_insert_sort(Iterator first, Iterator last, size_t chunk_size);

#endif
