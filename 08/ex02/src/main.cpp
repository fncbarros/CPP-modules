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

void	rprint(int i) {
	std::cout << i << std::endl;
}

int main()
{
	{
		std::cout << "***std::list output***\n";
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
		
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
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
	
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << s.top() << " = ";	
	std::cout << mstack.top() << std::endl;
	std::cout << s.size() << " = ";	
	std::cout << mstack.size() << std::endl;	
	std::cout << std::endl;

	MutantStack<int> mstack2(mstack); // <----

	std::for_each(mstack.rbegin(), mstack.rend(), rprint);

	return 0;
}
