#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include "Contact.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;
using std::setw;
using std::right;



class PhoneBook {
private:
	Contact contact[8];
	int _count;
public:
	void	search();
	void	selectindex();
	void	showperson(int count);
	void	add (int count);
	int		name(int count);
	int		lastname(int count);
	int		nickname(int count);
	int		number(int count);
	int		secret(int count);
};

void setsearchpr();

#endif
