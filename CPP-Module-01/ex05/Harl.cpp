#include "Harl.h"

Harl::Harl(){
	tmp[0] = &Harl::debug;
	tmp[1] = &Harl::info;
	tmp[2] = &Harl::warning;
	tmp[3] = &Harl::error;
}

void Harl::complain(std::string level) {
	while (level == "debug"){
		(this->*tmp[0])();
		break ;
	}
	while (level == "info"){
		(this->*tmp[1])();
		break ;
	}
	while (level == "warning"){
		(this->*tmp[2])();
		break ;
	}
	while (level == "error"){
		(this->*tmp[3])();
		break ;
	}
}

void Harl::debug() {
    cout << BLUE << "[DEBUG]" << RESET << " I love having extra bacon for my 7XL-double-cheese-triple-"
			"pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info() {
	cout << GREEN << "[INFO]" << RESET <<" I cannot believe adding extra bacon costs more money. You didn’t put "
			"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning() {
	cout << YELLOW <<"[WARNING]" << RESET << " I think I deserve to have some extra bacon for free. I’ve been coming for "
			"years whereas you started working here since last month." << endl;
}

void Harl::error() {
	cout << RED << "[ERROR]" << RESET << " This is unacceptable! I want to speak to the manager now." << endl;
}