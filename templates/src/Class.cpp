
#include "Class.hpp"

Class::Class( ) {

}

Class::Class(const Class& other) {
	if (this != &other)
	{
		*this = other;
	}
}

Class& Class::operator=(const Class& other) {
	if (this != &other)
	{
		// ...
	}
	return *this;
}

Class::~Class( ) {

} ;
