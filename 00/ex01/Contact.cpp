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

void	Contact::print_list(void){
	cout << "Name: " << this->Name << endl;
	cout << "Surname: " << this->Surname << endl;
	cout << "Nickname: " << this->Nickname << endl;
	cout << "Number: " << this->Number << endl;
	cout << "Secret: " << this->Secret << endl;
}