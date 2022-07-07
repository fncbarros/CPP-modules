/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:51:28 by fbarros           #+#    #+#             */
/*   Updated: 2022/07/07 15:47:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// AAnimal abstract();
	AAnimal *animalptr = new Cat();
	Cat	*catptr = (Cat *)animalptr;
	catptr->getBrain()->addIdea("idea1");
	catptr->getBrain()->addIdea("idea2");
	Cat	cat(*catptr);

	cat.getBrain()->printIdeas();

	delete catptr;

	return 0;
}

