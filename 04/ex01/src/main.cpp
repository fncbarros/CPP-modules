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
	std::cout << "####### Initializing array of Animal pointers #########\n";
	Animal	*animals[4];

	std::cout << "\n####### animals[0](pointing at Cat) #########\n";
	animals[0] = new Cat();

	std::cout << "\n####### animals[1](pointing at Cat copied from animals[0]) #########\n";
	animals[1] = new Cat(*((Cat *)animals[0]));

	std::cout << "\n####### animals[2](pointing at Dog) #########\n";
	animals[2] = new Dog();
	std::cout << "\n####### Dog* (pointing at animals[2]) #########\n";
    Dog *dog = (Dog *)animals[2];
    {
        std::cout << "\n####### Dog& (pointing at animals[2]) #########\n";
        Dog& dogref = *dog;
        Dog& dogref2(*dog);
        dogref.makeSound();
        dogref2.makeSound();
    }
	std::cout << "\n####### animals[3](pointing at Dog copied from dog(animals[2])) #########\n";
	animals[3] = new Dog(*dog);

	std::cout << std::endl;

	std::cout << "\n####### dog2 #########\n";

	std::cout << std::endl;

	((Cat *)animals[0])->getBrain()->addIdea("eat");
	((Cat *)animals[0])->getBrain()->addIdea("sleep");
	((Cat *)animals[0])->getBrain()->addIdea("stretch");

	std::cout << std::endl;

	std::cout << "\n####### animals[0](pointing at Cat) ideas #########\n";
    Cat *cat1 = (Cat *)animals[0];
	cat1->getBrain()->printIdeas();
    {
        std::cout << "\n####### building fakeCat from animals[0] #########\n";
        Cat fakeCat(*cat1);
        fakeCat.getBrain()->addIdea("fly");
        fakeCat.getBrain()->printIdeas();
    }
    dog->getBrain()->addIdea("catch tail");
    dog->getBrain()->addIdea("mess with neighboors lawn");
    Dog	dog2 = *dog;
    dog2.getBrain()->addIdea("fetch ball");
    dog2.getBrain()->addIdea("return ball");
    std::cout << "\n####### dog(animals[2]) ideas #########\n";
    dog->getBrain()->printIdeas();
    std::cout << "\n####### dog2(copy constructed from dog) ideas #########\n";
    dog2.getBrain()->printIdeas();

	std::cout << std::endl;

	delete animals[3];
	delete animals[2];
	delete animals[1];
	delete animals[0];

	return 0;
}

