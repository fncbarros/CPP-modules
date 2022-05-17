
#pragma once
#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <iostream>
// # include <iomanip>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class Class {

private:
	std::string _name;

public:

	Class( void );
	Class( std::string name );
	~Class( void );

std::string	getName( void ) const;

};

#endif /* CLASS_H */
