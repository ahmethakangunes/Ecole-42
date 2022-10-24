#include "PhoneBook.h"

int PhoneBook::name(int count)
{
	string command;
	cout << "Name --> ";
	getline(cin, command);
	if (cin.eof())
		exit (0);
	if (command.empty()) {
		while (1) {
			cout << "Name cannot be empty." << endl;
			cout << "Name --> ";
			getline(cin, command);
			if (command.size() > 0)
				break ;
			if (cin.eof())
				exit (0);
		}
	}
	contact[count].setName(command);
	return (1);
}

int PhoneBook::lastname(int count)
{
	string command;
	cout << "Lastname --> ";
	getline(cin, command);
	if (cin.eof())
		exit (0);
	if (command.empty()) {
		while (1) {
			cout << "Lastname cannot be empty." << endl;
			cout << "Lastname --> ";
			getline(cin, command);
			if (command.size() > 0)
				break ;
			if (cin.eof())
				exit (0);
		}
	}
	contact[count].setLastname(command);
	return (1);
}

int PhoneBook::nickname(int count)
{
	string command;
	cout << "Nickname --> ";
	getline(cin, command);
	if (cin.eof())
		exit (0);
	if (command.empty()) {
		while (1) {
			cout << "Nickname cannot be empty." << endl;
			cout << "Nickname --> ";
			getline(cin, command);
			if (command.size() > 0)
				break ;
			if (cin.eof())
				exit (0);
		}
	}
	contact[count].setNickname(command);
	return (1);
}

int PhoneBook::number(int count)
{
	string command;
	cout << "Number --> ";
	getline(cin, command);
	if (cin.eof())
		exit (0);
	if (command.empty()) {
		while (1) {
			cout << "Number cannot be empty." << endl;
			cout << "Number --> ";
			getline(cin, command);
			if (command.size() > 0)
				break ;
			if (cin.eof())
				exit (0);
		}
	}
	contact[count].setNumber(command);
	return (1);
}

int PhoneBook::secret(int count)
{
	string command;
	cout << "Secret --> ";
	getline(cin, command);
	if (cin.eof())
		exit (0);
	if (command.empty()) {
		while (1) {
			cout << "Secret cannot be empty." << endl;
			cout << "Secret --> ";
			getline(cin, command);
			if (command.size() > 0)
				break ;
			if (cin.eof())
				exit (0);
		}
	}
	contact[count].setSecret(command);
	return (1);
}

void PhoneBook::showperson(int count)
{
	system("clear");
	cout << "Name: " << contact[count].getName() << endl;
	cout << "Lastname: " << contact[count].getLastname() << endl;
	cout << "Nickname: " << contact[count].getNickname() << endl;
	cout << "Number: " << contact[count].getNumber() << endl;
	cout << "Secret: " << contact[count].getSecret() << endl;
	std::cout << "Please press Enter.";
	getchar();
}

void PhoneBook::selectindex()
{
	string command;
	while (1) {
		cout << "\n" << "Select Person --> ";
		getline(cin, command);
		if (command.empty())
			cout << "Field cannot be empty. Try again.";
		else if (!isdigit(command[0]))
			cout << "Wrong input ! Please try again.";
		else if (atoi(command.c_str()) > 7)
			cout << "Wrong input ! Please try again.";
		else if (contact[command[0] - 48].getName().empty()) {
			cout << "Upps... Empty.." << endl;
			cout << "Please Press Enter.";
			getchar();
			break ;
		}
		else {
			showperson(atoi(command.c_str()));
			break ;
		}
	}
}

void PhoneBook::search()
{
	int i;

	i = -1;
	while (contact[++i].getName().size() > 0)
	{
		if (i == 0)
			setsearchpr();
		cout << right << setw(9) << i << "|";
		if (contact[i].getName().size() < 10)
			cout << right << setw(10) << contact[i].getName() << "|";
		else
			cout << right << setw(8) << contact[i].getName().substr(0, 9) << ".|";
		if (contact[i].getLastname().size() < 10)
			cout << right << setw(10) << contact[i].getLastname() << "|";
		else
			cout << right << setw(8) << contact[i].getLastname().substr(0, 9) << ".|";
		if (contact[i].getNickname().size() < 10)
			cout << right << setw(10) << contact[i].getNickname() << "|" << endl;
		else
			cout << right << setw(8) << contact[i].getNickname().substr(0, 9) << ".|" << endl;
	}
	if (i == 0) {
		cout << "Upps... Empty.." << endl;
		cout << "Please press Enter.";
		getchar();
	}
	else
		selectindex();
}

void PhoneBook::add(int count)
{
	system("clear");
	name(count);
	lastname(count);
	nickname(count);
	number(count);
	secret(count);
	system("clear");
}