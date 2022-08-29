/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:26:36 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/29 15:26:46 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct s_data {
    int data_element;
} Data;

uintptr_t   serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*   deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data data;
    uintptr_t ptr;

    ptr = serialize(&data);
    std::cout << "Serialized: " << std::hex << ptr << std::endl;
    std::cout << "Deserialized: " << deserialize(ptr) << std::endl;
    std::cout << "data address: " << &data << std::endl;
    return 0;
}

