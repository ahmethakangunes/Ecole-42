#include "Zombie.h"


Zombie* zombieHorde( int N, std::string name){
	Zombie *newZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		newZombie[i].setName(name);
	return (newZombie);
}