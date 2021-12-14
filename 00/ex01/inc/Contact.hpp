/**
 * "Any function implemented in a header
 *  (except in the case of templates), and anyunprotected header means 0 to the exercise."
 * 
 * "Each of your includes must be able to be included 
 * independently from others.Includes must contain every other includes they are depending on."
*/

#ifndef PHONE_HPP
#define PHONE_HPP

# include <iostream>
# include <string>
# include <iomanip>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class	Contact{
	private:
		string	Name;
		string Surname;
		string Nickname;
		string	Number;
		string	Secret;
	public:
		Contact(void);
		~Contact(void);
		void	add(void);
		void	print_list(void);
};

#endif
