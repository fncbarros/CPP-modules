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
	std::cout << "####### Animal *i(pointing at Cat) #########\n";
	Animal	*i = new Cat();
	std::cout << "\n####### Animal *j(pointing at Dog) #########\n";
	Animal	*j = new Dog();


	((Cat *)i)->getBrain()->addIdea("eat");
	((Cat *)i)->getBrain()->addIdea("sleep");
	((Cat *)i)->getBrain()->addIdea("stretch");

	std::cout << std::endl;

	std::cout << "\n####### Cat *x(pointing at *i)#########\n";
    Cat *x = (Cat *)i;
	std::cout << "\n####### *x ideas:\n";
	x->getBrain()->printIdeas();
    {
        std::cout << "\n####### building fakeCat from *x #########\n";
        Cat fakeCat(*x);
        fakeCat.getBrain()->addIdea("fly");
		std::cout << "\n####### fakeCat ideas:\n";
        fakeCat.getBrain()->printIdeas();
		std::cout << "\n####### *x ideas:\n";
		x->getBrain()->printIdeas();
    }
	std::cout << "\n####### Dog *y(pointing at *j)#########\n";
    Dog *y = (Dog *)j;
	y->getBrain()->addIdea("catch tail");
    y->getBrain()->addIdea("mess with mailman");

    Dog	z = *y;
    z.getBrain()->addIdea("fetch ball");
    z.getBrain()->addIdea("return ball");
    std::cout << "\n####### *y ideas #########\n";
    y->getBrain()->printIdeas();
    std::cout << "\n####### z ideas:\n";
    z.getBrain()->printIdeas();

	std::cout << std::endl;

	delete j;
	delete i;

	return 0;
}

