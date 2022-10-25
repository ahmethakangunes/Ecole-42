#include "main.h"

void replace(string filename, string s1, string s2){

	ifstream input(filename, std::ios::in);
	ofstream output(filename + ".replace");
    if (input.fail() || output.fail()) {
        if (input.fail())
            cout << "File not found.";
        else
            cout << "Failed to create new file.";
        exit (0);
    }
    string newfile;
	char c;
	while(input.get(c)) {
        newfile.push_back(c);
        while (newfile.find(s1) < newfile.size()) {
            int x = newfile.find(s1, s1.size());
            if (newfile.find(s1))
                newfile.erase(newfile.find(s1), s1.size());
            newfile.insert(x, s2);
        }
    }
    output << newfile;
}

int main(){

	string filename;
	string s1;
	string s2;

    cout << "Filename: ";
	getline(cin, filename);
    cout << "String 1: ";
	getline(cin, s1);
    cout << "String 2: ";
	getline(cin, s2);
	replace(filename, s1, s2);
}