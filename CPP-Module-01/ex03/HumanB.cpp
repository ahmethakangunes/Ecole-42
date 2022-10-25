#include "HumanB.h"

HumanB::HumanB() {};

HumanB::HumanB(string name) {
	_name = name;
};

void HumanB::setWeapon(Weapon &_classname){
	_wpn = &_classname;
}

void HumanB::attack()
{
	cout << _name << " attacks with their " << _wpn->getType() << std::endl;
}