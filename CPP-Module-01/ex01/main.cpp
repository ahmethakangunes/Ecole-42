#include "Zombie.h"

int main(){
	int N;

	N = 15;
	Zombie *arrayZombie = zombieHorde(N, "ahmet");

	for (int i = 0; i < N; i++) {
		cout << "Zombie count = " << i << " ";
		arrayZombie[i].announce();
	}
	delete[] arrayZombie;

}