#include "phonebook.hpp"

int PhoneBook::control(std::string *contact, std::string variable){
	std::cout << variable << ": ";
	std::getline(std::cin, *contact);
	if (contact->length() <= 0)
		return (0);
	return (1);
}

void clearstring(PhoneBook *PhoneBook)
{
	std::cout << "Field cannot be empty. Please press enter to continue.";
	PhoneBook->Name.clear();
	PhoneBook->Lastname.clear();
	PhoneBook->Nickname.clear();
	PhoneBook->Number.clear();
	PhoneBook->Secret.clear();
	std::cin.get();
}

void printcolon(){
	system("reset");
	std::cout << std::setw(11) << std::right << "Index|";
	std::cout << std::setw(11) << std::right << "First Name|";
	std::cout << std::setw(11) << std::right << "Last Name|";
	std::cout << std::setw(12) << std::right << "Nick Name|\n";
}

void show(PhoneBook PhoneBook[8]){
    int i;
    std::string command;

    i = -1;
	printcolon();
    while (++i < 8){
		PhoneBook[i].search(&PhoneBook[i], i);
		std::cout << "\n";
	}
	selectindex(PhoneBook);
}

int selectindex(PhoneBook PhoneBook[8]){
	std::string index;

	std::cout << "Select index = ";
	std::getline(std::cin, index);
	if (isdigit(index[0]) && std::stoi(index) <= 7){
		system("clear");
		int count = stoi(index);
		PhoneBook->listindex(&PhoneBook[count]);
	}
	else
	{
		std::cout << "Wrong number ! Press Enter to continue.";
		std::cin.get();
		return (0);
	}
	return (1);
}