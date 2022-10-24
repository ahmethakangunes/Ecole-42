#include "PhoneBook.h"

void setprompt()
{
	cout << "ADD --> Add a person" << endl;
	cout << "SEARCH --> Search person" << endl;
	cout << "EXIT --> Exit program." << endl;
	cout << "Command --> ";
}

void setsearchpr()
{
	cout << right << setw(10) << "Index|";
	cout << right << setw(11) << "Name|";
	cout << right << setw(11) << "Lastname|";
	cout << right << setw(11) << "Nickname|" << endl;
}

int main(void) {
	system("clear");
	PhoneBook PhoneBook;

	int count;

	count = 0;
	while (1)
	{
		string command;
		setprompt();
		getline(cin, command);
		if (command == "ADD")
		{
			PhoneBook.add(count);
			count++;
		}
		else if (command == "SEARCH") {
			system("clear");
			PhoneBook.search();
			system("clear");
		}
		else if (command == "EXIT")
			exit (0);
		else if (cin.eof())
			exit (0);
		else
		{
			system("clear");
			cout << "Command not found. Please press Enter." << endl;
		}
	}
}