#include "Zombie.h"

Zombie::~Zombie() {
	cout << "Deconstructor Called for " << _name << endl;
}

void Zombie::announce() {
	cout << "Name = " << _name << endl;
}