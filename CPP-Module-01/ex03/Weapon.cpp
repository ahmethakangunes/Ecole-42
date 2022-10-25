#include "Weapon.h"

Weapon::Weapon(){};

Weapon::Weapon(string name) {
	setType(name);
}

void Weapon::setType(string name) {
	_type = name;
}

string &Weapon::getType() {
	return _type;
}
