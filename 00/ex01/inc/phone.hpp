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
		void	add(void) {
			cout << "Name:" <<endl;
			cin >> Name;
			cout << "Surname:" <<endl;
			cin >> Surname;
			cout << "Nickname:" <<endl;
			cin >> Nickname;
			cout << "Number:" <<endl;
			cin >> Number;
			cout << "Secret:" <<endl;
			cin >> Secret;
		};
};

#endif
