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
    std::clock_t start = std::clock();  // get initial time
    insertion_sort(_vector);
    std::clock_t end = std::clock();  // get finish time
    
    // calculate time difference
    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    _vectorTime *= 1000u; // to miliseconds
}

void PmergeMe::runDeque()
{
    std::clock_t start = std::clock();  // get initial time
    insertion_sort(_deque);
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
                break ;
            }
        }
        std::cout << std::endl;
        return ;
    }
    std::cerr << "Error: containers don't match" << std::endl;
}

template<class T>
void insertion_sort(T& data)
{
    typename T::iterator left = data.begin();
    typename T::iterator right = data.end() - 1;

    for (typename T::iterator it = left; (it <= right && it != data.end()); it++)
    {
        unsigned int key = *it;
        typename T::iterator j = it - 1;

        while (j >= left && *j > key)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

// template<class T>
// void merge(T& data, size_t left, size_t mid, size_t right)
// {
//     T left_half(data.begin() + left, data.begin() + mid + 1);
//     T right_half(data.begin() + mid, data.begin() + right + 1);

//     size_t it = 0, j = 0;
//     size_t k = left;

//     while (i < left_half.size() && j < right_half.size())
//     {
//         if (left_half[i] <= right_half[j])
//         {
//             data[k++] = left_half[i++];
//         }
//         else
//         {
//             data[k++] = right_half[j++];
//         }
//     }

//     while (k < left_half.size())
//     {
//         data[k++] = right_half[j++];
//     }
// }

// template<class T>
// void merge_insertion_sort(T& data, size_t left, size_t right)
// {
//     if ((right - left) < 20)
//     {
//         insertion_sort(data, left, right);
//         return ;
//     }

//     if (left < right)
//     {
//         size_t mid = left + (right - left) / 2;
//         merge_insertion_sort(data, left, mid);
//         merge_insertion_sort(data, mid + 1, right);
//         merge(data, left, mid, right);
//     }
// }
