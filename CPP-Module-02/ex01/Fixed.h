#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed {
private:
    int _fixednumber;
    const static int _fractionalpoint = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int  number);
    Fixed(const float number);
    Fixed &operator=(const Fixed &obj);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);


#endif
