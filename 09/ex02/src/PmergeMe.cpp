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

    while (!ss.eof())
    {
        ss >> num;
        if (num < 0)
        {
            std::cout << "Error: Negative number found => " << num << std::endl;
            return ;
        }
        _vector.push_back(static_cast<unsigned int>(num));
        _set.insert(static_cast<unsigned int>(num));
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
        this->_set = other._set;
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

// void PmergeMe::runSet()
// {
//     merge_insertion_sort(_set, 0u, (_vector.size() / 2) + 1);
// }

void PmergeMe::runBoth()
{
    runVector();
    // runSet();

    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    // for (size_t i = 0; i < _vector.size(); i++)
    //     std::cout << _set.find(i) << " ";
    // std::cout << std::endl;
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

