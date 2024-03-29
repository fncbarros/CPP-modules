
#pragma once
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	FragTrap(std::string name);
	virtual ~FragTrap();

	virtual void attack(const std::string& target);
	void highFivesGuys(void);

private:

};

#endif /* FRAGTRAP_H */
