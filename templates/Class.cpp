
#include "Class.hpp"

Class::Class( void ) {
	// ...
} ;

Class::Class( std::string name ) : _name(name) {} ;

Class::~Class( void ) {
	// ...
} ;

std::string	Class::getName( void ) const {
	return (_name);
} ;
