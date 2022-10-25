#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <iostream>

using std::string;
using std::endl;
using std::cout;

class Zombie {
private:
	string Name;
public:
	void	announce(void);
	void	setName(string name) {Name = name;}
	string	getName() {return Name;}
	~Zombie();

};

Zombie* newZombie(std::string name);
void randomchump(std::string name);

#endif
