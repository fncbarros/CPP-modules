/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 12:27:20 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animals[4];

	animals[0] = new Cat();
	animals[1] = new Cat(*((Cat *)animals[0]));

	animals[2] = new Dog();
	Dog *dog = (Dog *)animals[2];
	animals[3] = new Dog(*dog);

	std::cout << std::endl;

	Dog	dog2 = *dog;
	dog2 = *((Dog *)animals[3]);

	std::cout << std::endl;

	((Cat *)animals[0])->getBrain()->addIdea("eat");
	((Cat *)animals[0])->getBrain()->addIdea("sleep");
	((Cat *)animals[0])->getBrain()->addIdea("stretch");
	dog->getBrain()->addIdea("fetch ball");
	dog->getBrain()->addIdea("return ball");
	std::cout << std::endl;
	((Cat *)animals[0])->getBrain()->printIdeas();
	dog->getBrain()->printIdeas();

	std::cout << std::endl;

	delete animals[3];
	delete animals[2];
	delete animals[1];
	delete animals[0];

	return 0;
}

