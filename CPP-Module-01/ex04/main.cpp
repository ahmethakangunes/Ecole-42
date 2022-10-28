#include "main.h"

void replace(string filename, string s1, string s2){

	ifstream input(filename, std::ios::in);
    if (input.fail()) {
		cout << "File not found.";
        exit (0);
    }
	ofstream output(filename + ".replace");
	if (output.fail()){
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

int main(int argc, char **argv){
	if (argc == 4)
		replace(argv[1], argv[2], argv[3]);
	else
		cout << "Wrong input.";
	return (0);
}