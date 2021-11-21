/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:26:41 by fbarros           #+#    #+#             */
/*   Updated: 2021/11/15 11:26:43 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv){
	if (argc < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if (argv[i][j] > 96 && argv[i][j] < 123)
				{
					argv[i][j] -= 32;
					std::cout<<argv[i][j];
				}
				else
					std::cout<<argv[i][j];
			}
		}
		std::cout<<std::endl;
	}
}
