/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:06:11 by fbarros           #+#    #+#             */
/*   Updated: 2022/08/12 19:33:32 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

int	main(void)
{
	string str = "HI THIS IS BRAIN";
	string	*string_pointer = &str;
	string	&string_reference = str;

	cout << "Address of str:            " << &str << endl;
	cout << "Address held by string_pointer: " << string_pointer << endl;
	cout << "Address held by string_reference: " << &string_reference << endl;

	cout << "Value of str:                  " << str << endl;
	cout << "Value pointed to by string_pointer: " << *string_pointer << endl;
	cout << "Value pointed to by string_reference: " << string_reference << endl;
}