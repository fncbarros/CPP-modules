#include "Contact.hpp"

Contact::Contact(void) {
	// cout << "Constructor called." << endl;
}

Contact::~Contact(void) {
	// cout << "Destructor called." << endl;
}

void	Contact::add(void) {
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


/* Any output longer than the columns’ width is truncated and the
last displayable character is replaced by a dot (’.’).*/
void	Contact::options(int index) {
	cout << setfill(' ') << setw(10);
	cout << index + 1 << " | " ;
	cout << setfill(' ') << setw(10);
	cout << this->Name << " | " ;
	cout << setfill(' ') << setw(10);
	cout << this->Surname << " | " ;
	cout << setfill(' ') << setw(10);
	cout << Nickname << " | " << endl;
};
