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
            std::cout << "Error." << std::endl;
            return ;
        }
        _vector.push_back(static_cast<unsigned int>(num));
        _deque.insert(_deque.end(), static_cast<unsigned int>(num));
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
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
    merge_insertion_sort(_vector, 0u, (_vector.size() / 2) + 1);
}

void PmergeMe::runSet()
{
    merge_insertion_sort(_deque, 0u, (_vector.size() / 2) + 1);
}

void PmergeMe::runBoth()
{
    // get initial time
    std::clock_t vectorStart = std::clock();
    
    runVector();
    std::clock_t vectorEnd = std::clock();

    std::clock_t dequeStart = std::clock();
    runSet();
    std::clock_t dequeEnd = std::clock();

    // compute delta time
    vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC;
    dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC;

    printOrderedSequence();
    std::cout << "Time to process a range of 3000 elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::deque : " << dequeTime << " us" << std::endl;
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
                break ;
            }
        }
        std::cout << std::endl;
        return ;
    }
    std::cerr << "Error: containers don't match" << std::endl;
}

template<class T>
void insertion_sort(T& data, size_t left, size_t right)
{
    for (size_t i = left + 1; i < right; i++)
    {
        unsigned int key = data[i];
        size_t j = i - 1;

        while (j >= left && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

template<class T>
void merge(T& data, size_t left, size_t mid, size_t right)
{
    T left_half(data.begin() + left, data.begin() + mid + 1);
    T right_half(data.begin() + mid, data.begin() + right + 1);

    size_t i, j = {0};
    size_t k = left;

    while (i < left_half.size() && j < right_half.size())
    {
        if (left_half[i] <= right_half[j])
        {
            data[k++] = left_half[i++];
        }
        else
        {
            data[k++] = right_half[j++];
        }
    }

    while (i < left_half.size())
    {
        data[k++] = right_half[j++];
    }
}

template<class T>
void merge_insertion_sort(T& data, size_t left, size_t right)
{
    if ((right - left) < 20)
    {
        insertion_sort(data, left, right);
        return ;
    }

    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        merge_insertion_sort(data, left, mid);
        merge_insertion_sort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}
