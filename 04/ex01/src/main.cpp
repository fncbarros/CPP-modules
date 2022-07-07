/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/01 13:07:23 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "####### Initializing array of Animal * #########\n";
	Animal	*animals[4];

	std::cout << "\n####### animals[0](pointing at Cat) #########\n";
	animals[0] = new Cat();
	std::cout << "\n####### animals[1](pointing at Cat copied from animals[0]) #########\n";
	animals[1] = new Cat(*((Cat *)animals[0]));

	std::cout << "\n####### animals[2](pointing at Dog) #########\n";
	animals[2] = new Dog();
	std::cout << "\n####### dog(pointing at animals[2]) #########\n";
	Dog *dog = (Dog *)animals[2];
	std::cout << "\n####### animals[3](pointing at Dog copied from dog(animals[2])) #########\n";
	animals[3] = new Dog(*dog);

	std::cout << std::endl;

	// copy constructor called here
	std::cout << "\n####### dog2 #########\n";
	Dog	dog2 = *dog;
	dog2 = *((Dog *)animals[3]);

	std::cout << std::endl;

	((Cat *)animals[2])->getBrain()->addIdea("eat");
	((Cat *)animals[2])->getBrain()->addIdea("sleep");
	((Cat *)animals[2])->getBrain()->addIdea("stretch");
	dog2.getBrain()->addIdea("fetch ball");
	dog2.getBrain()->addIdea("return ball");
	std::cout << std::endl;
	std::cout << "\n####### animals[0](pointing at Cat) ideas #########\n";
	((Cat *)animals[0])->getBrain()->printIdeas();
	std::cout << "\n####### dog/animals[2] ideas #########\n";
	dog->getBrain()->printIdeas();

	std::cout << std::endl;

	delete animals[0];
	delete animals[1];
	delete animals[2];
	delete animals[3];

	return 0;
}

