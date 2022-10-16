/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:46:57 by fbarros           #+#    #+#             */
/*   Updated: 2022/10/15 17:48:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

void	print(int i) {
	std::cout << i << std::endl;
}

int main()
{
	{
		std::cout << "\n***std::list output***\n";
		std::list<int>	list;

		list.push_back(5);
		list.push_back(17);
		
		std::cout << list.back() << std::endl;
		
		list.pop_back();
		
		std::cout << list.size() << std::endl;
		
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		std::cout << std::endl;

		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		std::cout << "\nreverse printing using iterators" <<std::endl;
		std::for_each(list.rbegin(), list.rend(), print);		

	}

	std::cout << "\n***MutantStack output***\n";
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << std::endl;
	
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	std::cout << "\nreverse printing using iterators:\n"; // reverse printing from here on for better visualization
	std::for_each(mstack.rbegin(), mstack.rend(), print);

	std::cout << "\n***Copy constructing Mutant stack to mstack2***\n";
	MutantStack<int> mstack2(mstack);
	std::cout << "*POP*\n*POP*\n";
	mstack2.pop();
	mstack2.pop();

	std::cout << "\n**mstack2:\n";

	std::for_each(mstack2.rbegin(), mstack2.rend(), print);
	std::cout << "\n**mstack:\n";
	std::for_each(mstack.rbegin(), mstack.rend(), print);

	{
		std::cout << "\n***Constructing std::stack from MutantStack***\n" << std::endl;
		std::stack<int> s(mstack);

		std::cout << "stack top = " << s.top() << "\tmstack top = " << mstack.top() << std::endl;
		std::cout <<  "stack size = " << s.size() << "\tmstack size = " <<mstack.size() << std::endl;
		std::cout << std::endl;

		s = mstack2;
		std::cout << "Copied mstack2 to stack\nstack size now is " << s.size() << std::endl;
	}

	std::cout << "\n**Copied mstack to mstack2**\n";
	mstack2 = mstack;
	std::cout << "mstack2 values:\n";
	std::for_each(mstack2.rbegin(), mstack2.rend(), print);
	
	std::cout << std::endl;

	return 0;
}
