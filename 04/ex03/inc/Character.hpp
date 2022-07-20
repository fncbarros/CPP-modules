#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class ICharacter;

struct Floor {
    Floor();
    ~Floor();
    AMateria**   mptr;
    int idx;
};

static Floor    _floor;

class Character : public ICharacter {
public:
    Character(const std::string name);
    Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    static void drop(AMateria* m);
    static AMateria *pickup(std::string type);

private:
    AMateria*    _slot[4];
    std::string _name;
    // static Floor    _floor;

};

#endif /* CHARACTER_H */