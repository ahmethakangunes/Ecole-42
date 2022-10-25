#include "Zombie.h"

void Zombie::announce() {
	cout <<  this->Name << ":BraiiiiiiinnnzzzZ..." << endl;
}


void randomchump(std::string name) {
	Zombie Zombie;
	Zombie.setName(name);
	Zombie.announce();
}