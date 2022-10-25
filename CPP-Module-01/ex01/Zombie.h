#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Zombie {
private:
	string _name;
public:
	void setName(string name) {_name = name;}
	void announce();
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
