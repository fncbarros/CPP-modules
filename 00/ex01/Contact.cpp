#include "Contact.hpp"

Contact::Contact(void) {
	// cout << "Constructor called." << endl;
	exists = 0;
}

Contact::~Contact(void) {
	// cout << "Destructor called." << endl;
}

void	Contact::add(void) {
	exists = 1;
	cout << "Name:" <<endl;
	getline(cin, Name);
//	cin >> Name;
	cout << "Surname:" <<endl;
	getline(cin, Surname);
//	cin >> Surname;
	cout << "Nickname:" <<endl;
	getline(cin, Nickname);
//	cin >> Nickname;
	cout << "Number:" <<endl;
	getline(cin, Number);
//	cin >> Number;
	cout << "Secret:" <<endl;
	getline(cin, Secret);
//	cin >> Secret;
};


/* Any output longer than the columns’ width is truncated and the
last displayable character is replaced by a dot (’.’).*/
bool	Contact::options(int index) {
	if (!exists)
		return (false);
	cout << setfill(' ') << setw(10);
	cout << index + 1 << " | " ;
	cout << setfill(' ') << setw(10);
	cout << Name << " | " ;
	cout << setfill(' ') << setw(10);
	cout << Surname << " | " ;
	cout << setfill(' ') << setw(10);
	cout << Nickname << " | " << endl;
	return (true);
};

bool	Contact::show(void) {
	if (!exists)
		return (false);
	cout << "Name: " << Name << endl;
	cout << "Surname: " << Surname << endl;
	cout << "Nickname: " << Nickname << endl;
	cout << "Number: " << Number << endl;
	cout << "Secret: " << Secret << endl;
	return (true);
}
