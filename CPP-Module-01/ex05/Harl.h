#ifndef HARL_H
#define HARL_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Harl {
public:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void complain(string level);
};


#endif
