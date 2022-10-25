#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(){
	string brain = "HI THIS IS BRAIN";
	string *stringPTR = &brain;
	string &stringREF = brain;

	cout << &brain << endl;
	cout << &(*stringPTR) << endl;
	cout << &stringREF << endl;

	cout << brain << endl;
	cout << *stringPTR << endl;
	cout << stringREF << endl;
}