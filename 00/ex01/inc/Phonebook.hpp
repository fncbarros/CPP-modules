/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:04 by fbarros           #+#    #+#             */
/*   Updated: 2022/04/30 19:54:56 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook{
	private:

		class Contact	list[8];
		int	index;
		size_t size;

	public:
	
		Phonebook(void);
		~Phonebook(void);
		void			addContact(void);
		class Contact	getContact(int index);
		void			options(void);
};



#endif
