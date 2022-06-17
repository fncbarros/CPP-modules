
#include "Class.hpp"

Class::Class( void ) {

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
		*this = Class(other);
	}
	return *this;
}

Class::~Class( void ) {

} ;
