/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:06:17 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/10 20:06:42 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>
#include <iomanip>
#include <algorithm>


template<typename Iterator>
void insertion_sort(Iterator left, Iterator right);

template<typename Iterator>
void merge_insert_sort(Iterator first, Iterator last);

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::stringstream& ss)
{
    int num;

    while (true)
    {
        ss >> num;
        if (ss.eof())
        {
            break ;
        }
        if (num < 0 || ss.fail())
        {
            _vector.clear();
            _deque.clear();
            return ;
        }
        _vector.push_back(static_cast<unsigned int>(num));
        _deque.insert(_deque.end(), static_cast<unsigned int>(num));
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }

    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::runVector()
{
    // size_t chunk = (_vector.size() <= 10u) ? 10u : _vector.size();
    std::clock_t start = std::clock();  // get initial time
    merge_insert_sort(_vector.begin(), _vector.end() - 1u);
    std::clock_t end = std::clock();  // get finish time
    
    // calculate time difference
    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    _vectorTime *= 1000u; // to miliseconds
}

void PmergeMe::runDeque()
{
    // size_t chunk = (_vector.size() <= 10u) ? 10u : _vector.size();
    std::clock_t start = std::clock();  // get initial time
    merge_insert_sort(_deque.begin(), _deque.end() - 1u);
    std::clock_t end = std::clock();  // get finish time

    // calculate time difference
    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    _dequeTime *= 1000u; // to miliseconds
}

void PmergeMe::runBoth()
{
    runVector();
    runDeque();

    printOrderedSequence();
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
    std::cout << _vectorTime << std::setprecision(10) << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
    std::cout << _dequeTime << std::setprecision(10) << " us" << std::endl;
}

bool PmergeMe::containersSet()
{
    return (!_vector.empty() && !_deque.empty());
}


void PmergeMe::printOrderedSequence()
{
    size_t size = _vector.size();

    if (_deque.size() == size)
    {
        std::cout << "After: ";
        for (size_t i = 0; i < size; i++)
        {
            if (_vector[i] == _deque[i])
            {
                std::cout << _vector[i] << " ";
            }
            else
            {
                std::cerr << "Error: containers don't match" << std::endl;
                return ;
            }
        }
        std::cout << std::endl;
        return ;
    }
    std::cerr << "Error: containers don't match" << std::endl;
}

template<typename Iterator>
void insertion_sort(Iterator left, Iterator right)
{
    for (Iterator it = left; it <= right; it++)
    {
        unsigned int key = *it;
        Iterator j = it - 1;

        while (j >= left && *j > key)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

// Merge-insert sort using iterators
template<typename Iterator>
void merge_insert_sort(Iterator first, Iterator last)
{
    const size_t chunk_size = 10u;
    size_t size = std::distance(first, last);

    if (size <= 1u)
    {
        return ;
    }

    Iterator middle = first + size / 2;

    // Sort each chunk using insertion sort
    if (chunk_size >= size)
    {
        insertion_sort(first, last);
    }
    else
    {
        merge_insert_sort(first, middle);
        merge_insert_sort(middle, last);
        // Merge sorted chunks using merge sort
        std::inplace_merge(first, middle, last);
    }
}
