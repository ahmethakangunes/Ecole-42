#include "phonebook.hpp"

void PhoneBook::print(std::string text){
	if (text.length() > 10)
		std::cout << std::right << std::setw(8) << text.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << text;
}

void PhoneBook::add(PhoneBook *PhoneBook){

	system("clear");
	if(!control(&Name, "Name") || !control(&Lastname, "Lastname") || \
	!control(&Nickname, "Nickname") || !control(&Number, "Number") \
	|| !control(&Secret, "Secret")){
		clearstring(PhoneBook);
		return ;
	}
}

void PhoneBook::search(PhoneBook *PhoneBook, int index){
	std::cout << std::setw(10) << std::right << index;
	std::cout << "|";
	print(PhoneBook->Name);
	std::cout << "|";
	print(PhoneBook->Lastname);
	std::cout << "|";
	print(PhoneBook->Nickname);
	std::cout << "|";
}

void PhoneBook::listindex(PhoneBook *PhoneBook){
	if (PhoneBook->Name.length() == 0)
	{
		std::cout << "Upps! Empty....\n";
		std::cout << "Please press enter to continue.";
		std::cin.get();
		system("reset");
		return ;
	}
	std::cout << "First Name = " << PhoneBook->Name << std::endl;
	std::cout << "Last Name = " << PhoneBook->Lastname << std::endl;
	std::cout << "Nickname = " << PhoneBook->Nickname << std::endl;
	std::cout << "Number = " << PhoneBook->Number << std::endl;
	std::cout << "Secret = " << PhoneBook->Secret << std::endl;
	std::cout << "Please press enter to continue.";
	std::cin.get();
	system("reset");
}


int main(){
    PhoneBook PhoneBook[8];
    std::string command;
    int person;

    person = 0;
    while(1){
		system("clear");
		std::cout << "Add person -> ADD\n";
		std::cout << "Search person -> SEARCH\n";
		std::cout << "Exit -> EXIT\n";
		std::cout << "Command ----> ";
		std::getline(std::cin, command);
        if (command.compare("ADD") == 0){
            person %= 8;
			PhoneBook[person].add(&PhoneBook[person]);
            person++;
        }
    	else if (command.compare("SEARCH") == 0)
			show(PhoneBook);
		else if (command.compare("EXIT") == 0)
			exit (0);
		else
		{
			std::cout << "No such command was found. Please press enter to continue.";
			std::cin.get();
		}
    }
    return (0);
}