/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:04:33 by fbarros           #+#    #+#             */
/*   Updated: 2022/09/26 19:04:36 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( )
: index(0) {
	std::cout << "Brain default constructor called.\n";
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called.\n";
	if (this != &other)
	{
		*this = other;
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called.\n";
	if (this != &other)
	{
		this->index = other.index;
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::addIdea(std::string idea) {
	this->ideas[this->index++] = idea;
}

void	Brain::printIdeas(void) const {
		for (int i = 0; ideas[i].empty() == false ; i++)
			std::cout << ideas[i] << std::endl;
}

Brain::~Brain( ) {
	std::cout << "Brain destructor called.\n";
} ;
