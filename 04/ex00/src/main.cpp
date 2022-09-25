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
	std::cout << "**TEST1**\n\n";

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	/**
	 * @brief Testing constructors
	 *
	 */
	{
		std::cout << "**TEST2**\n\n";
		Cat cat = *(Cat *)i;
		std::cout << "Copy cat sound:\n";
		cat.makeSound();
		Dog dog(*(Dog *)j);
		std::cout << "Copy dog sound:\n";
		dog.makeSound();
	}

	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;

	/**
	 * @brief Animal Testing is Wrong
	 *
	 */
	{
		std::cout << "**TEST3**\n\n";

		const WrongAnimal *wmeta = new WrongAnimal();
		const WrongAnimal *wi = new WrongCat();
		const Animal *wj = new Dog();
		std::cout << wj->getType() << " " << std::endl;
		std::cout << wi->getType() << " " << std::endl;
		wi->makeSound(); // will output the animal sound!
		wj->makeSound();
		wmeta->makeSound();

		std::cout << std::endl;

		delete wj;
		delete wi;
		delete wmeta;
	}

	return (0);
}
