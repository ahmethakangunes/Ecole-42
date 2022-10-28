#include "Harl.h"

int main(int argc, char **argv)
{
	Harl Harl;

	if (argc == 2)
		Harl.complain(argv[1]);
	else
		cout << "Wrong input";
}