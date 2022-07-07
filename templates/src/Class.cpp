
#include "Class.hpp"

Class::Class() {
	// std::cout << "[Class] Default constructor called.\n";
}

Class::Class(const Class& other) {
	// std::cout << "[Class] Copy constructor called.\n";
	if (this != &other)
	{
		*this = other;
	}
}

Class& Class::operator=(const Class& other) {
	// std::cout << "[Class] Assignment operator called.\n";
	if (this != &other)
	{
		// this->(...) = other.(...)
	}
	return *this;
}

Class::~Class() {
	// std::cout << "[Class] Destructor called.\n";
} ;
