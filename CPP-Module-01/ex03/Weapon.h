#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>


using std::string;
using std::cout;
using std::endl;

class Weapon {
private:
	string _type;
public:
	Weapon();
	Weapon(string name);
	void setType(string name);
	string &getType();
};


#endif
