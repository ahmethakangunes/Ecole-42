#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

using std::string;

class HumanA {
private:
	Weapon *_wpn;
	string _name;
public:
	HumanA(std::string name, Weapon &_classname);
	void attack();
	void setWeapon(Weapon &_classname);
};


#endif
