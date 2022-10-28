#ifndef HARL_H
#define HARL_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl();
	void (Harl::*tmp[4])(void);
	void complain(string level);

};


#endif
