/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:05:18 by fbarros           #+#    #+#             */
/*   Updated: 2023/04/10 20:05:58 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error." << std::endl;
        return 1;
    }

    std::stringstream ss;
    std::vector<unsigned int> vec;

    for (int i = 1; i < argc; i++)
    {
        ss << std::string(argv[i]);
        ss << " ";
    }

    merge_insertion_sort(vec, 0U, (vec.size() / 2) + 1);

    PmergeMe pm(ss);
    pm.runBoth();

}
