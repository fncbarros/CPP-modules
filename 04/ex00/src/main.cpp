/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/29 17:40:08 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	/**
	 * @brief Copied from subject
	 * 
	 */
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;

	/**
	 * @brief Testing constructors
	 * 
	 */
	Cat	cat = *(Cat *)i;
	std::cout << "Copy cat sound:\n";
	cat.makeSound();
	Dog	dog(*(Dog *)j);
	std::cout << "Copy dog sound:\n";
	dog.makeSound();

	std::cout << std::endl;

	/**
	 * @brief Animal Testing is Wrong
	 * 
	 */
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();

	std::cout << wi->getType() << " " << std::endl;

	wi->makeSound(); //will output the animal sound!
	wmeta->makeSound();

	std::cout << std::endl;

	return (0);
}

