/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:06:11 by fbarros           #+#    #+#             */
/*   Updated: 2022/05/12 20:18:17 by fbarros          ###   ########.fr       */
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
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << "Address of str:            " << &str << endl;
	cout << "Address held by stringPTR: " << stringPTR << endl;
	cout << "Address held by stringREF: " << &stringREF << endl;

	cout << "Value of str:                  " << str << endl;
	cout << "Value pointed to by stringPTR: " << *stringPTR << endl;
	cout << "Value pointed to by stringREF: " << stringREF << endl;
}