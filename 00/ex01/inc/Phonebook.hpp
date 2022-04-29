/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:04 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/29 19:03:28 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook{
	private:

		class Contact	list[8];
		int	index;

	public:
	
		Phonebook(void);
		~Phonebook(void);
		void			addContact(void);
		class Contact	getContact(int index);
};

#endif
