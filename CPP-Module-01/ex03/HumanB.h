#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"


class HumanB {
private:
	string _name;
	Weapon *_wpn;
public:
	HumanB();
	HumanB(string name);
	void setWeapon(Weapon &_classname);
	void attack();
};


#endif
