#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <unistd.h>
# include <iomanip>

class PhoneBook{
private:
	std::string	Name;
	std::string	Lastname;
	std::string	Nickname;
	std::string	Number;
	std::string	Secret;
public:
	void	add(PhoneBook *PhoneBook);
	void	search(PhoneBook *PhoneBook, int index);
	void	listindex(PhoneBook *PhoneBook);
	void	print(std::string text);
	int		control(std::string *contact, std::string variable);
	friend void clearstring(PhoneBook *PhoneBook);
};

int		selectindex(PhoneBook PhoneBook[8]);
void	show(PhoneBook PhoneBook[8]);
void	printcolon();
void	clearstring(PhoneBook *PhoneBook);

#endif