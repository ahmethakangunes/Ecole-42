#ifndef CONTACT_H
#define CONTACT_H

#include "PhoneBook.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Contact {
private:
	string _name;
	string _lastname;
	string _nickname;
	string _number;
	string _secret;
public:

	string getName() {return _name;}
	string getLastname() {return _lastname;}
	string getNickname() {return _nickname;}
	string getNumber() {return _number;}
	string getSecret() {return _secret;}

	void setName(string name) {_name = name;}
	void setLastname(string lastname) {_lastname = lastname;}
	void setNickname(string nickname) {_nickname = nickname;}
	void setNumber(string number) {_number = number;}
	void setSecret(string secret) {_secret = secret;}
};


#endif
