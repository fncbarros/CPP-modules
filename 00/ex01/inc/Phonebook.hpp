/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:34:04 by fbarros           #+#    #+#             */
/*   Updated: 2022/03/08 16:08:05 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook{
	private:

		class Contact	list[8];
		static int		index; // ??
	
	public:
	
		Phonebook(void);
		~Phonebook(void);
		void			add(void);
		class Contact	getContact(int index);
};

#endif
