
#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <algorithm>

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void	addIdea(std::string idea);
	void	printIdeas() const ;

private:
	std::string	ideas[100];
	int	index;
};

#endif /* BRAIN_HPP */
