/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:10:18 by fbarros           #+#    #+#             */
/*   Updated: 2022/06/09 17:22:07 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("ERROR");
    harl.complain("WARNING");
    return 0;
}