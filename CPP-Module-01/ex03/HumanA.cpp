#include "HumanA.h"


HumanA::HumanA(std::string name, Weapon &_classname) {
	_name = name;
	_wpn = &_classname;
}

void HumanA::attack() {
	cout << _name << " attacks with their " << _wpn->getType() << std::endl;
}
